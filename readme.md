# Testing Script

This Node.js script is designed to run tests, check for required files, and compile C code.

## Table of Contents

- [Testing Script](#testing-script)
  - [Table of Contents](#table-of-contents)
  - [Getting Started](#getting-started)
  - [Script Overview](#script-overview)
  - [Functions and Arguments](#functions-and-arguments)
    - [Command-Line Arguments](#command-line-arguments)
    - [Helper Functions](#helper-functions)
  - [Error Handling](#error-handling)
    - [Undefined Reference Errors](#undefined-reference-errors)

## Getting Started

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/jawadelyousfi17/libft-unit-test.git
    cd libft-unit-test
    ```

2. **Install Dependencies:**
   
      ```bash
      ./setup.sh
      ```

4. **Ensure Node.js and npm Are Installed:**

    This command-line tool uses the Node.js runtime. If Node.js and npm are not installed on your device, please install them first. You can follow the instructions provided here: [Node.js Installation Guide](https://docs.npmjs.com/downloading-and-installing-node-js-and-npm).

5. **Usage:**

    - **Test a Function:**

        Navigate to the directory containing your functions and run:

        ```bash
        libftu -f <fname>
        ```

        Replace `<fname>` with the name of the function you want to test.

    - **Include Additional Functions:**

        If the function relies on other functions, include them using the `-l` flag:

        ```bash
        libftu -f <fname> -l <included_function_names>
        ```

        Replace `<included_function_names>` with a space-separated list of function names.

    - **Check File Existence:**

        To check if all required files exist, run:

        ```bash
        libftu -check
        ```

    - **Update Repository:**

        Keep your repository up to date with:

        ```bash
        libftu -update
        ```
    - **Help:**

        Help menu :

        ```bash
        libftu -h
        ```
## Script Overview

The script performs the following tasks:

1. **Update Git Repository**: Updates the local Git repository using the `-u` argument.

2. **Check Files**: Verifies the existence of required files using the `-c` argument.

3. **Compile and Test**: Compiles the specified C function and runs tests. Handles various cases of missing files and links additional helper files if needed.

## Functions and Arguments

### Command-Line Arguments

- **`-u`**: Updates the Git repository.
- **`-c`**: Checks if all required files exist.
- **`-f <function_name>`**: Specifies the function to compile and test.
- **`-l <helper_files>`**: Specifies additional helper C files to include in the compilation.

### Helper Functions

- **`getParams()`**: Parses command-line arguments.
- **`update_git(callback)`**: Updates the Git repository.
- **`checkFiles()`**: Checks if all required files exist.
- **`draw_intro(color)`**: Draws an introductory ASCII art.
- **`checkFiles()`**: Checks for the existence of files.

## Error Handling

### Undefined Reference Errors

If the compilation fails due to undefined references, the script will:

1. **Identify Missing Functions**: Extract function names from the error message.
2. **Suggest Solutions**: Prompt the user to include the missing functions in their C files or use the `-l` flag to link additional libraries.

**Example Error Message Handling:**

```bash
⚠️ Compilation error occurred:
Error: Undefined references to the following functions:
- ft_strlen
Please include these functions in your C files.
Or use the '-l' flag to link the additional functions required.
For example: libftu -f <function_name> -l ft_strlen
