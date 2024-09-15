#!/bin/bash

# Define colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
CYAN='\033[0;36m'
RESET='\033[0m' # No Color

SCRIPT_NAME="run_test.sh"
TARGET_DIR="/opt/libftu"

#Make sure node js is intalled

# Make sure the script is executable
#echo -e "${CYAN}Making the script executable...${RESET}"
chmod +x "$SCRIPT_NAME"
if [ $? -ne 0 ]; then
    echo -e "❌ ${RED}Failed to make $SCRIPT_NAME executable.${RESET}" >&2
    exit 1
fi

# Copy the entire current directory to the target directory
#echo -e "${CYAN}Copying the current directory to $TARGET_DIR...${RESET}"
sudo cp -r "$(pwd)" "$TARGET_DIR"
if [ $? -ne 0 ]; then
    echo -e "❌ ${RED}Failed to copy files to $TARGET_DIR.${RESET}" >&2
    exit 1
fi

# Create a symbolic link in /usr/bin
#echo -e "${CYAN}Creating a symbolic link in /usr/bin...${RESET}"
sudo ln -s "$TARGET_DIR/$SCRIPT_NAME" /usr/bin/libftu
if [ $? -ne 0 ]; then
    echo -e "❌ ${RED}Failed to create a symbolic link.${RESET}" >&2
    exit 1
fi

# Output messages with colors and styles
echo -e "✅ ${GREEN}The script is installed and can be run using: ${GREEN}libftu${RESET}"
