const { exec } = require('child_process');
const os = require('os');



const reset = '\x1b[0m';
const bold = '\x1b[1m';
const blue = '\x1b[34m';
const yellow = '\x1b[33m';
const green = '\x1b[32m';
const red = '\x1b[31m'; // Red color

// Function to check if libbsd is installed
function isLibbsdInstalled(callback) {
  const platform = os.platform();
  if (platform == 'win32')
  {
    callback(true);
    return;
  }
  const command = 'ldconfig -p | grep libbsd';

  exec(command, (error, stdout, stderr) => {
    if (error) {
      console.error(`Error executing command: ${stderr}`);
      callback(false);
      return;
    }

    // Check if libbsd is in the output
    if (stdout.includes('libbsd')) {
      callback(true);
    } else {
      callback(false);
    }
  });
}

function printInstallationInstructions() {
    const platform = os.platform();
    switch (platform) {
      case 'linux':
        console.log(reset,'\rIt looks like `libbsd` is not installed. To install `libbsd` on Linux, run:');
        console.log(' $ sudo apt-get install libbsd-dev');  // For Debian-based systems
        console.log(' $ sudo yum install libbsd-devel');  // For Red Hat-based systems
        break;
  
      case 'darwin':
        console.log('It looks like `libbsd` is not installed. To install `libbsd` on macOS, run:');
        console.log('  brew install libbsd');
        break;
  
      default:
        console.log('Your operating system is not supported for automatic instructions. Please consult the documentation for installing `libbsd`.');
        break;
    }
  }

  /**
 * Ensure the given string ends with a '/'.
 * @param {string} str - The input string.
 * @returns {string} - The input string with a trailing '/' if it wasn't there already.
 */
function ensureTrailingSlash(str) {
  // Check if the string already ends with a '/'
  if (str.endsWith('/')) {
    return str; // Return the string as is if it ends with '/'
  }
  
  // Append a '/' to the end of the string
  return str + '/';
}
function buildTree(paths) {
  // Helper function to build the tree
  const tree = {};

  paths.forEach((path) => {
      const parts = path.split('/');
      let current = tree;

      parts.forEach((part, index) => {
          if (!current[part]) {
              current[part] = {};  // Create a new object for each part of the path
          }
          current = current[part]; // Move to the next level in the tree
      });
  });

  return tree;
}

// Helper function to print the tree in a tree-like format
function printTree(tree, indent = '') {
  Object.keys(tree).forEach((key, index, array) => {
      const isLast = index === array.length - 1;
      console.log(`${indent}${isLast ? '└──' : '├──'} ${key}`);
      printTree(tree[key], indent + (isLast ? '    ' : '│   '));
  });
}

// Example usage
const paths = [
  "app.js",
  "check_libsd.js",
  "LICENSE",
  "package.json",
  "README.md",
  "run.js",
  "tests/test_file1.c",
  "tests/test_file2.c",
  "your-folder-name/ft_strlen.c",
  "your-folder-name/ft_strlcpy.c"
];





module.exports = {
    isLibbsdInstalled,
    ensureTrailingSlash,
    printInstallationInstructions
  };