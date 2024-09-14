
const readline = require('readline');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');
const { isLibbsdInstalled, printInstallationInstructions, ensureTrailingSlash } = require('./check_libsd');
const { getParams } = require("./get_args")
const { update_git } = require("./update")
const { draw_done, draw_intro } = require('./ascii_drawing')
const { checkFiles } = require("./check_files")
const os = require('os');

//working directory
const currentDirectory = process.cwd();

const dirName = __dirname
console.log("first")


let failed = false;
const args = getParams();
const reset = '\x1b[0m';
const bold = '\x1b[1m';
const blue = '\x1b[34m';
const yellow = '\x1b[33m';
const green = '\x1b[32m';
const red = '\x1b[31m'; // Red color
const cyan = '\x1b[36m';



if (args.update) {
    console.log(blue, "\rUpdating...")
    update_git((err) => process.exit(err));
}
else if (args.check) {
    console.log(blue, "\rChecking files...");
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
    const functionNames = [
        "ft_atoi",
        "ft_strdup",
        "ft_strlcat",
        "ft_strnstr"
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
    valid : testf -f all
    valid : testf -u  
    valid : testf -update
    valid : testf -check
    valid : testf -c
        `);
        process.exit(1);
    }

    if(!functionNames.includes(args.f))
    {
        console.log("⚠️ No test available for this function : ",args.f);
        process.exit(1);
    }

    const err =  await checkFilesExist([''+args.f+'.c'])
    if (err)
    {
        console.log("⚠️",args.f,".c")
        process.exit(1);
    }
    const lbsdFlag = args.f == 'ft_strlcat' ? '-lbsd' : '';
    const parentPath = path.dirname(dirName);
    const command = `gcc ${parentPath}/src/test_${args.f}.c ${currentDirectory}/${args.f}.c ${lbsdFlag} -fsanitize=address -o launch.out`
    start(command);

    async function start(command) {
        exec(command, (error, stdout, stderr) => {
            if (error) {
                console.log("⚠️ An error occurred:");
                console.error(`Error executing command: ${error.message}`);
                return;
            }

            if (stderr) {
                console.log("⚠️ An error occurred:");
                console.error(`Command stderr: ${stderr}`);
                return;
            }
            let cmd = './testLaunch.out ' + args.f
            runTests(args.f);
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
                    console.log(`${red}\r⚠️ ${fname} Test failed${reset}`);
                    reject(error);  // Reject the promise on error
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
