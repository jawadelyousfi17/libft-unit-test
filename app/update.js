
const readline = require('readline');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');
const { isLibbsdInstalled, printInstallationInstructions, ensureTrailingSlash } = require('./check_libsd');
const { getParams } = require("./get_args")
const os = require('os');

//working directory



const args = getParams();
const reset = '\x1b[0m';
const bold = '\x1b[1m';
const blue = '\x1b[34m';
const yellow = '\x1b[33m';
const green = '\x1b[32m';
const red = '\x1b[31m'; // Red color
const cyan = '\x1b[36m';


  async function update_git(callback)
  {
    process.chdir(__dirname);
      exec('sudo git pull', (error, stdout, stderr) => {
            if (error) {
                console.error(`Error  ${error.message}`);
                return;
            }
            if (stderr) {
                console.error(green,`\r✅ Updated `,reset);
                return;
            }
            console.log(green,`\r✅ ${stdout}`,reset);
            callback(0);
            process.exit(1);
        });
  }


module.exports = {update_git}