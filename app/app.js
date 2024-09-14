
const readline = require('readline');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');
const { isLibbsdInstalled, printInstallationInstructions, ensureTrailingSlash } = require('./check_libsd');
const os = require('os');



const args = process.argv.slice(2); // Extract arguments

const reset = '\x1b[0m';
const bold = '\x1b[1m';
const blue = '\x1b[34m';
const yellow = '\x1b[33m';
const green = '\x1b[32m';
const red = '\x1b[31m'; // Red color
const cyan = '\x1b[36m';

let src_folder = args[0] ? args[0] : '';
src_folder = !src_folder? src_folder : ensureTrailingSlash(src_folder);
// Define the path to the src directory
const srcPath = path.join(__dirname, src_folder);
// Check if the directory exists

const make_command = src_folder ? 'make -C ' + src_folder : 'make'
const make_clean_command = src_folder ? 'make clean -C ' + src_folder : 'make clean'

console.log(blue, '\r', `
  
  ░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░░▒▓████████▓▒░ 
░▒▓████▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ 
  ░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░      ░▒▓█▓▒░ 
  ░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░      ░▒▓█▓▒░  
  ░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░     ░▒▓█▓▒░  
  ░▒▓█▓▒░      ░▒▓█▓▒░     ░▒▓█▓▒░    ░▒▓█▓▒░   
  ░▒▓█▓▒░▒▓███████▓▒░▒▓███████▓▒░     ░▒▓█▓▒░   
                                                
                                               
 `,
 yellow,
 "\r\nTest",
 "\nby: @jel-yous\n",
 "GitHub: https://github.com/jawadelyousfi17/libft\n",
 "If you encounter any issues or bugs,\n",
 "please report them on the GitHub page.\n");


 function log_dir()
 {
  console.log(`${reset}
    │
    ├── app.js
    ├── check_libsd.js
    ├── LICENSE
    ├── package.json
    ├── README.md
    ├── run.js
    ├── tests/
    │   └── ... (other test files)
    │ ${reset}
    ├── your-folder-name ${red}(${src_folder})${cyan} ↩ Add your folder here in the root directory ${reset}
    │   ├── ft_strlen.c
    │   ├── ... (all ft_functions)
    │   ├── Makefile
    │   └── libft.h
    │${reset}
    └── ... (other files)
       `)
 }

 function log_libft()
 {
  console.log(`${reset}
    │
    ├── app.js
    ├── check_libsd.js
    ├── LICENSE
    ├── package.json
    ├── README.md
    ├── run.js
    ├── tests/
    │   └── ... (other test files)
    │ ${cyan}
    ├── your-folder-name (${src_folder})  
    │   ├──${red} libfta.a ${cyan}     ↩ Add your libft.a here
    │   └── libft.h 
    │${reset}
    └── ... (other files)
       `)
 }

   if (!fs.existsSync(srcPath)) {
    console.error(`Directory ${src_folder} does not exist.`);
    log_dir();
    process.exit(1);
  }
// Array of file paths to check
const filesToCheck = [
  'ft_isalnum.c',
  'ft_isascii.c',
  'ft_isprint.c',
  'ft_memcpy.c',
  'ft_memset.c',
  'ft_strlcat.c',
  'ft_strlen.c',
  'ft_strncmp.c',
  'ft_strrchr.c',
  'ft_toupper.c',
  'ft_atoi.c',
  'ft_isalpha.c',
  'ft_isdigit.c',
  'ft_memcmp.c',
  'ft_memmove.c',
  'ft_strchr.c',
  'ft_strlcpy.c',
  'ft_strnstr.c',
  'ft_tolower.c',
  'ft_memchr.c',
  'ft_bzero.c',
  'ft_strdup.c',
  'ft_calloc.c',
  'Makefile',
];

// All tests Functions
const testFunctionsFiles = [
  'test_ft_isalpha.c',
  'test_ft_isdigit.c',
  'test_ft_isalnum.c',
  'test_ft_isascii.c',
  'test_ft_isprint.c',
  'test_ft_strlen.c',
  'test_ft_toupper.c',
  'test_ft_tolower.c',
  'test_ft_strchr.c',
  'test_ft_strrchr.c',
  'test_ft_strncmp.c',
  'test_ft_strlcpy.c',
  'test_ft_strlcat.c',
  'test_ft_strnstr.c',
  'test_ft_atoi.c',
  'test_ft_memset.c',
  'test_ft_memcmp.c',
  'test_ft_memcpy.c',
  'test_ft_memmove.c',
  'test_ft_memchr.c',
  'test_ft_bzero.c',
  'test_ft_strdup.c',
  'test_ft_calloc.c'
]

//update File to check
filesToCheck.forEach((fileName, index) => {
  filesToCheck[index] = src_folder + fileName;
})

const pathToTestsFunction = 'tests/test_functions/'
let allTestsFunctionsCommand = '';
testFunctionsFiles.forEach(testFunction => {
  allTestsFunctionsCommand += `${pathToTestsFunction}${testFunction} `
})


const status = [
  { text: '🔍 Checking files...', color: blue },
  { text: '⚙️ Processing...', color: green },
  { text: '✅ Complete!', color: green },
  { text: 'ERROR! some files are missing', color: red },
  { text: '✅ All files found', color: green },

];

const printStatus = (index) => {
  if (index < status.length) {
    console.log(`${status[index].color}${bold}${status[index].text}${reset}\n`);
  }
};


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

async function start(choice, makeFileChoice) {
  const fsanitize_flag = (choice == 1) ? '-fsanitize=address' : '';
  if (makeFileChoice == 1) {
    console.log(blue, bold, "\r🔍  Checking files ...")
    checkFilesExist(filesToCheck).then((err) => {
      if (err) {
        log_dir();
        console.log(red, bold, '\rERROR! some files are missing');
        console.log(red, bold, '\rStopping the application...');
        process.exit(0); // 0 indicates success
      }
      console.log(green, bold, "\r✅ All files exist");
      exec(make_command, (error, stdout, stderr) => {
        //console.log("\r")
        console.log(blue, bold, "\r⚙️  Executing make ...")
        if (error) {
          console.error(`❌ Error: \n${error.message}`);
          return;
        }
        if (stderr) {
          console.log(bold, `stderr: ${stderr}`);
          return;
        }
        if (stdout) { }
        console.log(green, bold, "\r✅ sucess!");
        exec(make_clean_command, (error, stdout, stderr) => {
        })
        console.log(blue, bold, "\r⚙️  Cleaning...");
        console.log(blue, bold, "\r⚙️  Compiling...");
        exec('gcc -Wall -Wextra -Werror tests/main.c ' + allTestsFunctionsCommand + src_folder + 'libft.a' + ' tests/libs/libmysd.a -lbsd ' + fsanitize_flag, (error, stdout, stderr) => {
          if (error) {
            console.error(bold, `\rError: \n${error.message}`);
            return;
          }
          if (stderr) {
            console.log(bold, `stderr: ${stderr}`);
            return;
          }
          if (stdout)
            console.log(`${stdout}`);
          console.log(green, "\r✅ Compiled!");
          console.log(blue, "\r⚙️  Running...");
          exec('./a.out -f', { timeout: 2500 }, (error, stdout, stderr) => {
            if (error && error.signal === 'SIGTERM') {
              console.log(red, "\r🕒  Time out... The command took too long to execute.");
              return;
            }
            if (stderr) {
              console.log("");
              if (stderr.includes("Assertion")) {
                const functionNameRegex = /ft_(\w+)/;

                // Extract the function name
                const match = stderr.match(functionNameRegex);

                console.log("❌ Test failed due to an assertion error");
                if (match && match[1]) {
                  console.log(`In function: ${match[0]}`);
                } else {
                  console.log("Function name could not be extracted.");
                }
              } else {
                console.log("⚠️ An error occurred:");
              }
              console.error(`❗ ERROR MESSAGE :`, reset, ` ${stderr}`);
              return;
            }
            if (stdout)
              console.log(`${stdout}`);
          });
        });
      });
    })
  } else {
    checkFileExists(src_folder+'libft.a').then((f_exist) => {
      if (!f_exist) {
        console.log("❌ libfta.a not found in : ",src_folder+'libft.a');
        console.log("Make sure you have libft.a");
        log_libft();
        process.exit(0);
      }
      console.log(blue, bold, "\r⚙️  Compiling...");
      exec('gcc -Wall -Wextra -Werror tests/main.c ' + allTestsFunctionsCommand + src_folder + 'libft.a  tests/libs/libmysd.a ' + fsanitize_flag, (error, stdout, stderr) => {
        // if (error) {
        //   console.error(bold, `\rError: \n${error.message}`);
        //   return;
        // }
        if (stderr) {
          if (stderr.includes("Assertion")) {
            const functionNameRegex = /ft_(\w+)/;
  
            // Extract the function name
            const match = stderr.match(functionNameRegex);
  
            console.log("❌ Test failed due to an assertion error");
            if (match && match[1]) {
              console.log(`In function: ${match[0]}`);
            } else {
              console.log("Function name could not be extracted.");
            }
          } else {
            console.log("⚠️ An error occurred:");
          }
          console.error(`❗ ERROR MESSAGE :`, reset, ` ${stderr}`);
          return;
        }
        if (stdout)
          console.log(`${stdout}`);
        console.log(green, "\r✅ Compiled!");
        console.log(green, "\r⚙️  --Running...");
        exec('./a.out -f', { timeout: 1500 }, (error, stdout, stderr) => {
          if (error) {
            if (error.code === 'ETIMEDOUT') {
              console.error('The command timed out.');
            } else 
              console.error(`Error: ${error.message}`);
            return;
          }
          if (stderr) {
            console.error(`stderr: ${stderr}`);
            return;
          }
          if (stdout)
            console.log(`${stdout}`);
        });
      });
    })
   
  }

}


// Create an interface for reading user input from the terminal
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false  // This prevents double input echoing
});



if (os.platform == 'win32') {
  console.log("❌ Sorry, this can't be run on Windows.\nPlease use a 🐧 Unix-based system like Linux or macOS.");
  console.log(reset, "\rFor Windows users, you can install WSL (Windows Subsystem for Linux) to run Unix-based commands: ", blue, "https://learn.microsoft.com/en-us/windows/wsl/install", reset)
  process.exit(0);
}


isLibbsdInstalled((isInstalled) => {
  if (!isInstalled) {
    console.log(bold, red, '\rlibbsd is not installed in your device ');
    printInstallationInstructions()
    process.exit(0);
  }
  console.log(bold, blue, '\r=== Please select an option or press ENTER for default ==== ');
  console.log(reset, '\r1. Compile with ', bold, '-fsanitize=address ', yellow, '( default )');
  console.log(reset, '\r2. Compile ', bold, 'without -fsanitize=address');
  rl.question('Enter your choice (1 or 2): ', (answer) => {
    let flags = 1;
    let flag2 = 1;
    switch (answer) {
      case '1':
        flags = 1;
        break;
      case '2':
        flags = 2;
        break;
      default:
        flags = 1;
        break;
    }
    //console.log(bold, blue, '\r\n=== Please select an option or press ENTER for default ==== ');
    console.log(yellow, '\r1. (default)', reset, ' Run ', bold, 'make', reset, 'command to generate libft.a then Test it ? (All Funcions source must be included)');
    console.log(reset, '\r2. You already have', bold, 'libft.a', reset, 'just test it', bold);
    rl.question('Enter your choice (1 or 2 or ENTER for default): ', answer => {
      switch (answer) {
        case '1':
          flag2 = 1;
          break;
        case '2':
          flag2 = 2;
          break;
        default:
          flag2 = 1;
          break;
      }
      start(flags, flag2);
      rl.close();
    })
  })

})

