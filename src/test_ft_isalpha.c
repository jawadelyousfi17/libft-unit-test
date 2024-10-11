#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../libs/c_strcmp.c"

int ft_isalpha(int c);

int _formate(int x)
{
    if (x)
        return 1;
    return 0;
}

typedef struct
{
    char test_case;
    int result;
    int expected;
} test_val;

#define TESTS_NBR 255

int main()
{
    test_val tests[TESTS_NBR];

    int i = 0;
    while (i < TESTS_NBR)
    {
        tests[i].test_case = i - 1;
        tests[i].result = ft_isalpha(tests[i].test_case);
        tests[i].expected = isalpha(tests[i].test_case);
        i++;
    }

    // MORE TEST TO DO

    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (_formate(tests[index].result)== _formate(tests[index].expected))
        {
            //printf("TEST %d ✅\n", index + 1);
        }
        else
        {
            printf("TEST %d ❌\n", index + 1);
            printf("   Test case : %cn", tests[index].test_case);
            printf("   Got : \"%d\"\n", tests[index].result);
            printf("   Expected : \"%d\"\n", tests[index].expected);
            sucess = 0;
            passed_tests--;
        }
        index++;
    }
    if (sucess)
    {
        printf("All tests passed ✅\n");
        return 0;
    }
    else
    {
        printf("FAILED ! %d / %d\n", passed_tests, TESTS_NBR);
    }
    return 1;
}