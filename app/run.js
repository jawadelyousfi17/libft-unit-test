const path = require('path');
const { getParams, getFunctionsToCheck } = require("./get_args");
const { update_git, isRepoUpToDate } = require("./update");
const { draw_done, draw_intro } = require('./ascii_drawing');
const { checkFiles, checkFilesExist } = require("./check_files");
const { showHelpMessages } = require('./help');
const launch = require('./launch_command');
const CompileFiles = require('./compile_function');
const colors = require('./colors');
const checkValidArgs = require('./check_args');

// Working directory and global variables
const currentDirectory = process.cwd();
const dirName = __dirname;
const args = getParams();
const functionNames = [
    "ft_atoi",
    "ft_strdup",
    "ft_strlcat",
    "ft_strnstr",
    "ft_itoa",
    "ft_substr",
    "ft_strjoin",
    "ft_strtrim",
    "ft_split",
    "ft_strlen",
    "ft_isalnum",
    "ft_isalpha",
    "ft_isascii",
    "ft_isdigit",
    "ft_isprint",
    "ft_tolower"
];

// Function to handle updates
const handleUpdate = () => {
    console.log(colors.blue, "\rUpdating...");
    update_git((err) => process.exit(err ? 1 : 0));
};

// Function to handle file checking
const handleFileCheck = async () => {
    console.log(colors.blue, "\rChecking files...");
    try {
        await checkFiles();
        console.log(colors.green, '\r✅ All files exist', colors.reset);
    } catch (err) {
        console.error(colors.red, '\r❌ Error checking files', colors.reset);
        process.exit(1);
    }
};

// Main test execution logic
const executeTests = async () => {
    draw_intro(colors.yellow);

    try {
        checkValidArgs(args);
        // Ensure the function to be tested is valid
        if (!functionNames.includes(args.f[0])) {
            console.log("⚠️ No test available for this function:", args.f[0]);
            process.exit(1);
        }
        const { functionsToCheck, helperFunctionsNames } = getFunctionsToCheck();
        const err = await checkFilesExist(functionsToCheck);
        if (err) {
            console.log("⚠️", args.f[0], ".c not found.");
            process.exit(1);
        }

        const lbsdFlag = args.f[0] === 'ft_strlcat' ? '-lbsd' : '';
        const fsanitizeFlag = args.s ? "" : "-fsanitize=address"
        const parentPath = path.dirname(dirName);
        const command = `gcc ${parentPath}/src/test_${args.f[0]}.c ${currentDirectory}/${args.f[0]}.c ${helperFunctionsNames} ${lbsdFlag} ${fsanitizeFlag} -o launch.out`;

        await CompileFiles(command);
        await launch(`./launch.out`, args.f[0]);

    } catch (err) {
        console.error(colors.red, "❌ An error occurred during execution:", err.message);
        process.exit(1);
    }
};

// Main logic based on passed arguments
if (args.u) {
    handleUpdate();
} else if (args.h) {
    showHelpMessages();
} else if (args.c) {
    handleFileCheck();
} else {
    executeTests();
}
