const path = require('path');
const { getParams, getFunctionsToCheck } = require("./get_args")
const { update_git, isRepoUpToDate } = require("./update")
const { draw_done, draw_intro } = require('./ascii_drawing')
const { checkFiles, checkFilesExist } = require("./check_files")
const { showHelpMessages } = require('./help');
const launch = require('./launch_command');
const CompileFiles = require('./compile_function');
const colors = require('./colors');
const checkValidArgs = require('./check_args');

//working directory && Global variables
const currentDirectory = process.cwd();
const dirName = __dirname
let failed = false;
const args = getParams();
const functionNames = [
    "ft_atoi",
    "ft_strdup",
    "ft_strlcat",
    "ft_strnstr",
    "ft_itoa",
    "ft_substr",
    "ft_strjoin",
    "ft_strtrim"
];



if (args.u) {
    console.log(colors.blue, "\rUpdating...")
    update_git((err) => process.exit(err));
} else if (args.h) {
    showHelpMessages()
}
else if (args.c) {
    console.log(colors.blue, "\rChecking files.....");
    checkFiles().then((err) => {
        if (!err) {
            console.log(colors.green, '\r✅ All files exist', colors.reset)
        }
    })
} else {
    (async () => {
        draw_intro(colors.yellow);
        checkValidArgs(args)
        if (!functionNames.includes(args.f[0])) {
            console.log("⚠️ No test available for this function : ", args.f[0]);
            process.exit(1);
        }
        const { functionsToCheck, helperFunctionsNames } = getFunctionsToCheck();
        const err = await checkFilesExist(functionsToCheck)
        if (err) {
            console.log("⚠️", args.f[0], ".c")
            process.exit(1);
        }
        const lbsdFlag = args.f[0] == 'ft_strlcat' ? '-lbsd' : '';
        const parentPath = path.dirname(dirName);
        const command = `gcc ${parentPath}/src/test_${args.f[0]}.c ${currentDirectory}/${args.f[0]}.c ${helperFunctionsNames} ${lbsdFlag} -fsanitize=address -o launch.out`
        CompileFiles(command)
            .then(async msg => await launch(`./launch.out`, args.f[0]))
            .catch(err => {})
    })()
}


