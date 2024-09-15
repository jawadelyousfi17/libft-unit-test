const args = process.argv.slice(2);

const parseArgs = (args) => {
  const flags = {};
  for (let i = 0; i < args.length; i += 2) {
    if (args[i].startsWith('-')) {
      if (args[i].substring(1) == 'update' || args[i].substring(1) == 'u') {
        flags['update'] = 'yes';
        i--;
      }
      else if (args[i].substring(1) == 'check' || args[i].substring(1) == 'c'){
        flags['check'] = 'yes';
        i--;
      }
      else {
        flags[args[i].substring(1)] = args[i + 1];
      }
    }
  }
  return flags;
};

const getArgs = (args) => {
  let i = 0;
  const result = {};
  while (i < args.length) {
      let arg = args[i];
      if (arg.startsWith("-"))
      {
          arg = arg.slice(1);
          if (arg === 'update')
              arg = 'u';
          if(arg === 'check')
              arg = 'c'
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

const flags = getArgs(args);

const getParams = () => {
  return flags;
}
module.exports = { getParams }
