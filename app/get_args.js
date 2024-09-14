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

const flags = parseArgs(args);

const getParams = () => {
  return flags;
}
// {f : "value", s : "value" .. } 
module.exports = { getParams }
