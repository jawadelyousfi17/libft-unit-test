#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/c_strcmp.c"

size_t ft_strlen(const char *s);

typedef struct {
    char* test_case;
    int result;
    int expected;
} test_val;

#define TESTS_NBR 1

int main()
{
    test_val tests[TESTS_NBR];

    // test 1 : base case
    tests[0].test_case = "1337";
    tests[0].result = ft_strlen(tests[0].test_case);
    tests[0].expected = strlen(tests[0].test_case);

    // MORE TEST TO DO


    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (tests[index].result == tests[index].expected)
        {
            printf("TEST %d ✅\n",index + 1);
        }
        else 
        {
            printf("TEST %d ❌\n",index + 1);
            printf("   Test case : %sn" ,tests[index].test_case);
            printf("   Got : \"%d\"\n" ,tests[index].result);
            printf("   Expected : \"%d\"\n" ,tests[index].expected);
            sucess = 0;
            passed_tests--;
        }
        index++;
    }
    if (sucess)
    {
        printf("All tests passed ✅\n");
        return 0;
    } else 
    {
        printf("FAILED ! %d / %d\n",passed_tests,TESTS_NBR);
    }
    return 1;
}