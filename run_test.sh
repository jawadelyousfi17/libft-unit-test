#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CYAN='\033[0;36m'
RESET='\033[0m' # No Color

# Get the current directory where the script is located
SCRIPT_DIR="$(dirname "$(realpath "$0")")"

# Check if Node.js is installed
# if command -v node >/dev/null 2>&1; then
#     echo "❌ Node.js is not installed."
#     echo "Please install Node.js before running this script."
#     echo "You can find installation instructions here: https://docs.npmjs.com/downloading-and-installing-node-js-and-npm"
#     exit 1
# else
#     echo "Node.js is installed."
# fi

# Construct the full path to your Node.js script
NODE_SCRIPT="$SCRIPT_DIR/app/run.js"

# Execute the Node.js script with any passed arguments
node "$NODE_SCRIPT" "$@"

#     const command = `gcc ${dirName}/tests/test_by_function.c ${__dirname}/tests/test_functions/libtest.a ${__dirname}/tests/libs/libmysd.a ` + libftPath +`  -fsanitize=address -o ${__dirname}/testLaunch.out `;
