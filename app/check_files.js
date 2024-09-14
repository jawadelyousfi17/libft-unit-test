const fs = require('fs');
const path = require('path');
const { filesToCheck } = require("./data")
const currentDirectory = process.cwd();

const reset = '\x1b[0m';
const bold = '\x1b[1m';
const blue = '\x1b[34m';
const yellow = '\x1b[33m';
const green = '\x1b[32m';
const red = '\x1b[31m'; // Red color
const cyan = '\x1b[36m';


const filesToCheckFullPath = filesToCheck.map(fileName => currentDirectory + '/' + fileName);

function checkFileExists(filePath) {
    return new Promise((resolve) => {
        fs.access(filePath, fs.constants.F_OK, (err) => {
            resolve(!err);
        });
    });
}

async function checkFiles() {
    files = filesToCheckFullPath;
    let err = false;
    for (let index = 0; index < filesToCheckFullPath.length; index++) {
        const file = filesToCheckFullPath[index];
        const absolutePath = path.resolve(file);
        const exists = await checkFileExists(absolutePath);
        if (!exists) {
            console.log(yellow,`\r⚠️  ${filesToCheck[index]}     is MISSING`,reset);
            err = true;
        }
    }
    return err;
}

module.exports = { checkFiles }