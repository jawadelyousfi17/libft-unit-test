#!/bin/bash

# Get the current directory where the script is located
SCRIPT_DIR="$(dirname "$(realpath "$0")")"

# Construct the full path to your Node.js script
NODE_SCRIPT="$SCRIPT_DIR/app/run.js"

# Execute the Node.js script with any passed arguments
node "$NODE_SCRIPT" "$@"

#     const command = `gcc ${dirName}/tests/test_by_function.c ${__dirname}/tests/test_functions/libtest.a ${__dirname}/tests/libs/libmysd.a ` + libftPath +`  -fsanitize=address -o ${__dirname}/testLaunch.out `;
