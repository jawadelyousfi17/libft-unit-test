const args_in = ["-f","ft_strdup","1","2","-l","ft_strlen","ft_strcpy","-u","-v"]

const getArgs = (args) => {
    let i = 0;
    const result = {};
    while (i < args.length) {
        let arg = args[i];
        if (arg.startsWith("-"))
        {
            arg = arg.slice(1);
            result[arg] = [];
            i++;
            let j = i;
            while (j < args.length && !args[j].startsWith("-") ) 
            {
                result[arg].push(args[j]);
                j++;
            }
            i += (j -i -1)
        }
        i++;
    }
    return result
}

console.log(args_in)
console.log(getArgs(args_in))
if(getArgs(args_in).u) 
{
    console.log("yes")
}