
const readline = require('readline');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');
const { isLibbsdInstalled, printInstallationInstructions, ensureTrailingSlash } = require('./check_libsd');
const { getParams } = require("./get_args")
const { update_git, isRepoUpToDate } = require("./update")
const { draw_done, draw_intro } = require('./ascii_drawing')
const { checkFiles } = require("./check_files")
const os = require('os');

//working directory
const currentDirectory = process.cwd();

const dirName = __dirname


let failed = false;
const args = getParams();
const reset = '\x1b[0m';
const bold = '\x1b[1m';
const blue = '\x1b[34m';
const yellow = '\x1b[33m';
const green = '\x1b[32m';
const red = '\x1b[31m'; // Red color
const cyan = '\x1b[36m';



if (args.u) {
    console.log(blue, "\rUpdating...")
    update_git((err) => process.exit(err));
} else if (args.h)
{
    console.log(`
        Usage:
          - libftu -f <fname>        : Test a specific function <fname>.
          - libftu -f <fname> -l <required_function_names> : Test a function and include additional required functions.
          - libftu -u                : Update the repository.
          - libftu -update           : Update the repository (alternative flag).
          - libftu -c                : Check if all required files exist.
          - libftu -check            : Check if all required files exist (alternative flag).
        
        Examples:
          - To test a function:
            libftu -f ft_strlen
        
          - To test a function with dependencies:
            libftu -f ft_strjoin -l ft_strlen ft_substr
        
          - To check if all files exist:
            libftu -check
        
          - To update the repository:
            libftu -update
        `);
}
else if (args.c) {
    console.log(blue, "\rChecking files.....");
    checkFiles().then((err) => {
        if (!err) {
            console.log(green, '\r✅ All files exist', reset)
        }
    })
} else {
    begin();
}

async function begin() {

    draw_intro(yellow);
    process.stdout.write(`Checking for updates...\r`);
    isRepoUpToDate();
    const functionNames = [
        "ft_atoi",
        "ft_strdup",
        "ft_strlcat",
        "ft_strnstr",
        "ft_itoa",
        "ft_substr",
        "ft_strjoin",
        "ft_strtrim"
    ];

    function checkFileExists(filePath) {
        return new Promise((resolve) => {
            fs.access(filePath, fs.constants.F_OK, (err) => {
                resolve(!err);
            });
        });
    }

    async function checkFilesExist(files) {
        let err = false;
        for (const file of files) {
            const absolutePath = path.resolve(file); // Resolve absolute path
            const exists = await checkFileExists(absolutePath);
            if (!exists) {
                console.error(`${file} ${exists ? 'exists' : 'is MISSING'}`);
                err = true;
            }
        }
        return err;
    }



    //check arg
    if (!args.f) {
        console.log(yellow, `\r❌ Error: Invalid args!${reset}
    Try this  intsted
    Valid : testf -f ft_strlen  [ or any function name ]
    valid : testf -u  
    valid : testf -update
    valid : testf -check
    valid : testf -c
        `);
        process.exit(1);
    }
    if (args.f.length > 1) {
        console.log(yellow, `\r❌ too many arguments for -f${reset}`)
        console.log(yellow, `\r❌ Error: Invalid args!${reset}
    Try this  intsted
    Valid : testf -f ft_strlen  [ or any function name ]
        `);
        process.exit(1);
    }
if (!functionNames.includes(args.f[0])) {
    console.log("⚠️ No test available for this function : ", args.f[0]);
    process.exit(1);
}
const helperFunctionsArgs = args.l;
let helperFunctionsNames = '';
const functionsToCheck = [];
functionsToCheck.push(args.f[0] + '.c')
if (args.l) {
    helperFunctionsArgs.forEach(fn => {
        helperFunctionsNames += currentDirectory + '/' + fn + '.c '
    });
    args.l.forEach((fn, index) => {
        args.l[index] = fn + '.c'
        functionsToCheck.push(args.l[index])
    })
}

const err = await checkFilesExist(functionsToCheck)
if (err) {
    console.log("⚠️", args.f[0], ".c")
    process.exit(1);
}
const lbsdFlag = args.f[0] == 'ft_strlcat' ? '-lbsd' : '';
const parentPath = path.dirname(dirName);
const command = `gcc ${parentPath}/src/test_${args.f[0]}.c ${currentDirectory}/${args.f[0]}.c ${helperFunctionsNames} ${lbsdFlag} -fsanitize=address -o launch.out`
start(command);

async function start(command) {
    exec(command, (error, stdout, stderr) => {
        if (error) {
            console.log("⚠️ Compilation error occurred:");
            if (error.message.includes("undefined reference to")) {
                const regex = /undefined reference to [`'"]([^`'"]+)['"]/g;
                let match;
                const missingFunctions = [];
                while ((match = regex.exec(stderr)) !== null) {
                    missingFunctions.push(match[1]);
                }
                let missingFnames = '';
                function removeDuplicates(arr) {
                    return arr.filter((item,
                        index) => arr.indexOf(item) === index);
                }
                if (missingFunctions) {
                    const missingFunctionsWithoutDuplicate = removeDuplicates(missingFunctions)
                    missingFunctionsWithoutDuplicate.forEach(fn => {
                        missingFnames += fn + ' '
                    })
                }
                console.log("Error: Undefined references to the following functions:");
                console.log(red, missingFnames, reset)
                console.log("Please include these functions in your C files.");
                console.log("Or use the '-l' flag to link the additional functions required.");
                console.log(`For example : ${cyan} libftu -f ${args.f[0]} ${yellow} -l ${missingFnames} ${reset}`);

            } else
                console.error(`Error executing command: ${error.message}`);
            return;
        }

        if (stderr) {
            console.log("⚠️ An error occurred:");
            console.error(`Command stderr: ${stderr}`);
            return;
        }
        let cmd = './testLaunch.out ' + args.f[0]
        runTests(args.f[0]);
    });
}

async function launch(command, fname) {
    return new Promise((resolve, reject) => {
        const prefix = `${blue}Running ${fname}`;
        process.stdout.write(`${prefix}...`);
        exec(command, { timeout: 2500 }, (error, stdout, stderr) => {
            process.stdout.write('\r');
            console.log(stdout);
            if (error && error.signal === 'SIGTERM') {
                console.log(yellow, "\r🕒  Time out... The function took too long to execute.");
                console.log(`${red}\r⚠️ ${fname} : Test failed${reset}`);
                failed = true;
                resolve(true);
                return;
            }
            if (error) {
                failed = true;
                console.log(error.message)
                console.log(`${red}\r⚠️ ${fname} Test failed${reset}`);
                reject(error);
                return;
            }

            if (stderr) {
                failed = true;
                console.log("⚠️ Test failed");
                console.error(`Command stderr: ${stderr}`);
                reject(new Error(stderr));  // Reject the promise on stderr
                return;
            }

            process.stdout.write(`${green}${bold}✓ ${fname} : Test passed${reset}                   \n`);
            resolve(stdout);  // Resolve the promise on success
        });
    });
}

async function runTests(fname) {
    if (fname !== 'all' || !fname) {
        try {
            console.log("running")
            await launch(`./launch.out`, fname);
        } catch (error) {
        }
    }
}

}
