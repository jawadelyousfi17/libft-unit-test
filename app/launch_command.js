const { exec } = require('child_process');
const colors = require('./colors');

async function launch(command, fname) {
    return new Promise((resolve, reject) => {
        exec(command, { timeout: 2500 }, (error, stdout, stderr) => {
            console.log(stdout);
            if (error && error.signal === 'SIGTERM') {
                console.log(colors.yellow, "\r🕒  Time out... The function took too long to execute.");
                console.log(`${colors.red}\r⚠️ ${fname} : Test failed${colors.reset}`);
                resolve(true);
                return;
            }
            if (error) {
                console.log(error.message)
                console.log(`${colors.red}\r⚠️ ${fname} Test failed${colors.reset}`);
                resolve(error);
                return;
            }

            if (stderr) {
                console.log("⚠️ Test failed");
                console.error(`Command stderr: ${stderr}`);
                resolve(new Error(stderr));  // Reject the promise on stderr
                return;
            }

            console.log(`${colors.green}${colors.bold}✓ ${fname} : Test passed${colors.reset}                   \n`);
            resolve(true);  // Resolve the promise on success
        });
    });
}

module.exports = launch