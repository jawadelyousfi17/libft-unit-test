function showHelpMessages()
{
    console.log(`
        Usage:
          - libftu -f <fname>        : Test a specific function <fname>.
          - libftu -f <fname> -l <required_function_names> : Test a function and include additional required functions.
          - libftu -u                : Update the repository.
          - libftu -update           : Update the repository (alternative flag).
          - libftu -c                : Check if all required files exist.
          - libftu -check            : Check if all required files exist (alternative flag).
        
        Examples:
          - To test a function:
            libftu -f ft_strlen
        
          - To test a function with dependencies:
            libftu -f ft_strjoin -l ft_strlen ft_substr
        
          - To check if all files exist:
            libftu -check
        
          - To update the repository:
            libftu -update
        `);
}

module.exports = {showHelpMessages}