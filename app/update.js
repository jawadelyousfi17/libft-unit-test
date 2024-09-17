
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

  async function isRepoUpToDate() {
    process.chdir(__dirname);
     return new Promise((resolve, reject) => {
         // Fetch latest changes from the remote
         exec('git fetch', (fetchError) => {
             if (fetchError) {
                 console.error('Error fetching from remote:', fetchError);
                 reject(fetchError)
             }
 
             // Check the status to see if we're behind or ahead of the remote branch
             exec('git status -uno', (statusError, stdout) => {
                 if (statusError) {
                     console.error('Error checking git status:');
                     reject(statusError)
                 }
                 // Parse the output of 'git status'
                 if (stdout.includes('Your branch is up to date')) {
                     console.log('Your repository is up to date.');
                 } else if (stdout.includes('Your branch is behind')) {
                     console.log('Your repository is behind the remote. Consider pulling.');
                     reject(true)
                 } else if (stdout.includes('Your branch is ahead')) {
                     console.log('Your repository is ahead of the remote. Consider pushing.');
                 } else {
                     console.log('Your repository status is unclear. Check manually.');
                 }
                 resolve(true);
             });
         });
     })
 
 }
 

 
module.exports = {update_git , isRepoUpToDate}