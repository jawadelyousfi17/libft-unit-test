
function getMissingFunctionsName(stderr) {
    const regex = /undefined reference to [`'"]([^`'"]+)['"]/g;
    let match;
    const missingFunctions = [];
    while ((match = regex.exec(stderr)) !== null) {
        missingFunctions.push(match[1]);
    }
    let missingFnames = '';
    function removeDuplicates(arr) {
        return arr.filter((item,
            index) => arr.indexOf(item) === index);
    }
    if (missingFunctions) {
        const missingFunctionsWithoutDuplicate = removeDuplicates(missingFunctions)
        missingFunctionsWithoutDuplicate.forEach(fn => {
            missingFnames += fn + ' '
        })
    }
    return missingFnames
}

module.exports = getMissingFunctionsName