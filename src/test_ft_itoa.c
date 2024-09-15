#include <stdio.h>
#include <stdlib.h>
#include "../libs/c_strcmp.c"

char *ft_itoa(int n);

typedef struct {
    int test_case;
    char *result;
    char *expected;
} test_val;

#define TESTS_NBR 21

int main()
{
    test_val tests[TESTS_NBR];

    // test 1 : base case
    tests[0].test_case = 1337;
    tests[0].result = ft_itoa(tests[0].test_case);
    tests[0].expected = strdup("1337");

    // test 2 : negative base case
    tests[1].test_case = -1337;
    tests[1].result = ft_itoa(tests[1].test_case);
    tests[1].expected = strdup("-1337");

    // test 3 : 0 base test case
    tests[2].test_case = 0;
    tests[2].result = ft_itoa(tests[2].test_case);
    tests[2].expected = strdup("0");

    // test 4 : MAX INT
    tests[3].test_case =  2147483647;
    tests[3].result = ft_itoa(tests[3].test_case);
    tests[3].expected = strdup("2147483647");

    // test 4 : MIN INT
    tests[4].test_case = -2147483648;
    tests[4].result = ft_itoa(tests[4].test_case);
    tests[4].expected = strdup("-2147483648");

    // test 5 : INT LEN 1
    tests[5].test_case = 8;
    tests[5].result = ft_itoa(tests[5].test_case);
    tests[5].expected = strdup("8");

    // test 6 : INT LEN 2
    tests[6].test_case = 13;
    tests[6].result = ft_itoa(tests[6].test_case);
    tests[6].expected = strdup("13");

    // test 7 : INT LEN 3
    tests[7].test_case = 133;
    tests[7].result = ft_itoa(tests[7].test_case);
    tests[7].expected = strdup("133");

    // test 8 : INT LEN 5
    tests[8].test_case = 13378;
    tests[8].result = ft_itoa(tests[8].test_case);
    tests[8].expected = strdup("13378");

    // test 9 : INT LEN 6
    tests[9].test_case = 133781;
    tests[9].result = ft_itoa(tests[9].test_case);
    tests[9].expected = strdup("133781");

    // test 11 : INT LEN 8
    tests[10].test_case = 13378125;
    tests[10].result = ft_itoa(tests[10].test_case);
    tests[10].expected = strdup("13378125");

    // test 12 : INT LEN 9
    tests[11].test_case = 895623145;
    tests[11].result = ft_itoa(tests[11].test_case);
    tests[11].expected = strdup("895623145");

    // test 13 : INT LEN 10
    tests[12].test_case = 1595623145;
    tests[12].result = ft_itoa(tests[12].test_case);
    tests[12].expected = strdup("1595623145");

    // NEGATIVE CASES

       // test 14 : INT LEN 1
    tests[13].test_case = -8;
    tests[13].result = ft_itoa(tests[13].test_case);
    tests[13].expected = strdup("-8");

    // test 15 : INT LEN 2
    tests[14].test_case = -29;
    tests[14].result = ft_itoa(tests[14].test_case);
    tests[14].expected = strdup("-29");

    // test 16 : INT LEN 3
    tests[15].test_case = -890;
    tests[15].result = ft_itoa(tests[15].test_case);
    tests[15].expected = strdup("-890");

    // test 17 : INT LEN 5
    tests[16].test_case = -93378;
    tests[16].result = ft_itoa(tests[16].test_case);
    tests[16].expected = strdup("-93378");

    // test 18 : INT LEN 6
    tests[17].test_case = -233781;
    tests[17].result = ft_itoa(tests[17].test_case);
    tests[17].expected = strdup("-233781");

    // test 19 : INT LEN 8
    tests[18].test_case = -13378125;
    tests[18].result = ft_itoa(tests[18].test_case);
    tests[18].expected = strdup("-13378125");

    // test 20 : INT LEN 9
    tests[19].test_case = -895623145;
    tests[19].result = ft_itoa(tests[19].test_case);
    tests[19].expected = strdup("-895623145");

    // test 21 : INT LEN 10
    tests[20].test_case = -1595623145;
    tests[20].result = ft_itoa(tests[20].test_case);
    tests[20].expected = strdup("-1595623145");


    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (custom_strcmp(tests[index].result , tests[index].expected) == 0)
        {
            printf("TEST %d ✅\n",index + 1);
        }
        else 
        {
            printf("TEST %d ❌\n",index + 1);
            printf("   Test case : %d\n" ,tests[index].test_case);
            printf("   Got : \"%s\"\n" ,tests[index].result);
            printf("   Expected : \"%s\"\n" ,tests[index].expected);
            sucess = 0;
            passed_tests--;
        }
        index++;
    }
    // clean
    index = 0;
    while (index < TESTS_NBR)
    {
        if (tests[index].result)
            free(tests[index].result);
        free(tests[index].expected);
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