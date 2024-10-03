const { exec } = require('child_process');
const colors = require('./colors');

function checkValidArgs(args)
{
    if (!args.f) {
        console.log(colors.yellow, `\r❌ Error: Invalid args!${colors.reset}
    Try this  intsted
    Valid : testf -f ft_strlen  [ or any function name ]
    valid : testf -u  
    valid : testf -update
    valid : testf -check
    valid : testf -c
        `);
        process.exit(1);
    }
    if (args.f.length > 1) {
        console.log(colors.yellow, `\r❌ too many arguments for -f${colors.reset}`)
        console.log(colors.yellow, `\r❌ Error: Invalid args!${colors.reset}
    Try this  intsted
    Valid : testf -f ft_strlen  [ or any function name ]
        `);
        process.exit(1);
    }
}
module.exports = checkValidArgs