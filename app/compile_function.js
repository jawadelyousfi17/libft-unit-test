const { exec } = require('child_process');
const { getParams } = require("./get_args");
const getMissingFunctionsName = require("./get_missing_functions");
const colors = require('./colors');
const args = getParams()

async function CompileFiles(command) {
    return new Promise((resolve, reject) => {
        exec(command, (error, stdout, stderr) => {
            if (error) {
                console.log("⚠️ Compilation error occurred:");
                if (error.message.includes("undefined reference to")) {
                    missingFnames = getMissingFunctionsName(stderr)
                    console.log("Error: Undefined references to the following functions:");
                    console.log(colors.red, missingFnames, colors.reset)
                    console.log("Please include these functions in your C files.");
                    console.log("Or use the '-l' flag to link the additional functions required.");
                    console.log(`For example : ${colors.cyan} libftu -f ${args.f[0]} ${colors.yellow} -l ${missingFnames} ${colors.reset}`);
                    reject(true)
                    return
                } else
                    console.error(`Error executing command: ${error.message}`);
                reject(true)
            }

            if (stderr) {
                console.log("⚠️ An error occurred:");
                console.error(`Command stderr: ${stderr}`);
                reject(true)
                return
            }
            resolve('./testLaunch.out ')
        });
    })

}

module.exports = CompileFiles