#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/c_strcmp.c"
#include "colors.h"

char *ft_strtrim(char const *s1, char const *set);

typedef struct
{
    char *test_case;
    char *set;
    char *result;
    char *expected;
} test_vals;

#define TESTS_NBR 22

int main()
{
    test_vals tests[TESTS_NBR];

    // Basic trimming with leading and trailing spaces
    tests[0].test_case = "   Hello ";
    tests[0].set = " ";
    tests[0].expected = "Hello";
    tests[0].result = ft_strtrim(tests[0].test_case, tests[0].set);

    // Multiple trimming characters
    tests[1].test_case = "-*-hello-jj-*--*";
    tests[1].set = "-*";
    tests[1].expected = "hello-jj";
    tests[1].result = ft_strtrim(tests[1].test_case, tests[1].set);

    // Trimming exclamation marks
    tests[2].test_case = "!!Welcome!!";
    tests[2].set = "!";
    tests[2].expected = "Welcome";
    tests[2].result = ft_strtrim(tests[2].test_case, tests[2].set);

    // Edge case: Empty input string
    tests[3].test_case = "";
    tests[3].set = " ";
    tests[3].expected = "";
    tests[3].result = ft_strtrim(tests[3].test_case, tests[3].set);

    // Edge case: Empty set
    tests[4].test_case = "Test";
    tests[4].set = "";
    tests[4].expected = "Test";
    tests[4].result = ft_strtrim(tests[4].test_case, tests[4].set);

    // Edge case: Input string contains only set characters
    tests[5].test_case = "*******";
    tests[5].set = "*";
    tests[5].expected = "";
    tests[5].result = ft_strtrim(tests[5].test_case, tests[5].set);

    // Trimming plus signs
    tests[6].test_case = "++trim me++";
    tests[6].set = "+";
    tests[6].expected = "trim me";
    tests[6].result = ft_strtrim(tests[6].test_case, tests[6].set);

    // Edge case: No characters to trim
    tests[7].test_case = "no trim";
    tests[7].set = "-";
    tests[7].expected = "no trim";
    tests[7].result = ft_strtrim(tests[7].test_case, tests[7].set);

    // Trimming characters from both ends
    tests[8].test_case = "   spaces   ";
    tests[8].set = " ";
    tests[8].expected = "spaces";
    tests[8].result = ft_strtrim(tests[8].test_case, tests[8].set);

    // Trimming multiple characters
    tests[9].test_case = "abcdabcdtest abcd testabcdabcd";
    tests[9].set = "abcd";
    tests[9].expected = "test abcd test";
    tests[9].result = ft_strtrim(tests[9].test_case, tests[9].set);

    // Edge case: All characters in set
    tests[10].test_case = "+++++++";
    tests[10].set = "+";
    tests[10].expected = "";
    tests[10].result = ft_strtrim(tests[10].test_case, tests[10].set);

    // Trimming tabs and newlines
    tests[11].test_case = "\n\ttrim this\n\t";
    tests[11].set = "\n\t";
    tests[11].expected = "trim this";
    tests[11].result = ft_strtrim(tests[11].test_case, tests[11].set);

    // Trimming characters not in the set
    tests[12].test_case = "###H####e####l#######################l######o###";
    tests[12].set = "#";
    tests[12].expected = "H####e####l#######################l######o";
    tests[12].result = ft_strtrim(tests[12].test_case, tests[12].set);

    // Edge case: Input string is NULL
    tests[13].test_case = NULL;
    tests[13].set = "-*";
    tests[13].expected = NULL;
    tests[13].result = ft_strtrim(tests[13].test_case, tests[13].set);

    // Edge case: Set is NULL
    tests[14].test_case = "Hello";
    tests[14].set = NULL;
    tests[14].expected = "Hello";
    tests[14].result = ft_strtrim(tests[14].test_case, tests[14].set);

    // Trimming special characters
    tests[15].test_case = "///++trim me++///";
    tests[15].set = "/+";
    tests[15].expected = "trim me";
    tests[15].result = ft_strtrim(tests[15].test_case, tests[15].set);

    // Trimming with overlapping set
    tests[16].test_case = "--**Hello World**--";
    tests[16].set = "-*";
    tests[16].expected = "Hello World";
    tests[16].result = ft_strtrim(tests[16].test_case, tests[16].set);

    // Edge case: Single character input
    tests[17].test_case = "x";
    tests[17].set = "x";
    tests[17].expected = "";
    tests[17].result = ft_strtrim(tests[17].test_case, tests[17].set);

    // Trimming numbers
    tests[18].test_case = "111222trim333444";
    tests[18].set = "1234";
    tests[18].expected = "trim";
    tests[18].result = ft_strtrim(tests[18].test_case, tests[18].set);

    // Edge case: Both s1 and set are empty
    tests[19].test_case = "";
    tests[19].set = "";
    tests[19].expected = "";
    tests[19].result = ft_strtrim(tests[19].test_case, tests[19].set);

    tests[20].test_case = "9911991199991991119111911991189191911911919191999191919199911919191";
    tests[20].set = "91";
    tests[20].expected = "8";
    tests[20].result = ft_strtrim(tests[20].test_case, tests[20].set);

    tests[21].test_case = ".   ..This is a little bit tricky!    .";
    tests[21].set = ". ";
    tests[21].expected = "This is a little bit tricky!";
    tests[21].result = ft_strtrim(tests[21].test_case, tests[21].set);

    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    
    while (index < TESTS_NBR)
    {
        if (custom_strcmp(tests[index].result, tests[index].expected) == 0)
        {
            printf("✅ TEST %d" " \n", index + 1);
        }
        else
        {
            printf(BG_RED "TEST %d FAILED" RESET "\n", index + 1);
            printf(RESET "   Test case : \"%s\" , set = \"%s\" \n", tests[index].test_case, tests[index].set);
            printf(TEXT_ORANGE "   Got : \"%s\"\n", tests[index].result);
            printf(TEXT_CYAN "   Expected : \"%s\"\n" RESET, tests[index].expected);
            sucess = 0;
            passed_tests--;
        }
        index++;
    }
    // clean
    index = 0;

    while (index < TESTS_NBR)
    {
        if (tests[index].result != NULL)
            free(tests[index].result);
        index++;
    }

    if (sucess)
    {
        printf("\n" STYLE_BOLD  "  All tests passed \n\n" RESET);
        return 0;
    }
    else
    {
        printf("\n" BG_RED "FAILED ! %d / %d" RESET "\n", passed_tests, TESTS_NBR);
    }
    return 1;
}