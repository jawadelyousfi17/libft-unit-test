#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/c_strcmp.c"

char *ft_strjoin(char const *s1, char const *s2);

typedef struct
{
    char *prefix;
    char *sufix;
    char *result;
    char *expected;
} test_vals;

#define TESTS_NBR 20

int main()
{
    test_vals tests[TESTS_NBR];

    tests[0].prefix = "Hello ";
    tests[0].sufix = "1337!";
    tests[0].expected = strdup("Hello 1337!");
    tests[0].result = ft_strjoin(tests[0].prefix, tests[0].sufix);

    tests[1].prefix = "foo";
    tests[1].sufix = "bar";
    tests[1].expected = strdup("foobar");
    tests[1].result = ft_strjoin(tests[1].prefix, tests[1].sufix);

    tests[2].prefix = "";
    tests[2].sufix = "empty";
    tests[2].expected = strdup("empty");
    tests[2].result = ft_strjoin(tests[2].prefix, tests[2].sufix);

    tests[3].prefix = "leading ";
    tests[3].sufix = "";
    tests[3].expected = strdup("leading ");
    tests[3].result = ft_strjoin(tests[3].prefix, tests[3].sufix);

    tests[4].prefix = " ";
    tests[4].sufix = "space";
    tests[4].expected = strdup(" space");
    tests[4].result = ft_strjoin(tests[4].prefix, tests[4].sufix);

    tests[5].prefix = "long_prefix_";
    tests[5].sufix = "long_suffix";
    tests[5].expected = strdup("long_prefix_long_suffix");
    tests[5].result = ft_strjoin(tests[5].prefix, tests[5].sufix);

    tests[6].prefix = "123";
    tests[6].sufix = "456";
    tests[6].expected = strdup("123456");
    tests[6].result = ft_strjoin(tests[6].prefix, tests[6].sufix);

    tests[7].prefix = "newline\n";
    tests[7].sufix = "test";
    tests[7].expected = strdup("newline\ntest");
    tests[7].result = ft_strjoin(tests[7].prefix, tests[7].sufix);

    tests[8].prefix = "prefix";
    tests[8].sufix = "\n";
    tests[8].expected = strdup("prefix\n");
    tests[8].result = ft_strjoin(tests[8].prefix, tests[8].sufix);

    tests[9].prefix = "\t";
    tests[9].sufix = "tab";
    tests[9].expected = strdup("\ttab");
    tests[9].result = ft_strjoin(tests[9].prefix, tests[9].sufix);

    tests[10].prefix = "";
    tests[10].sufix = "";
    tests[10].expected = strdup("");
    tests[10].result = ft_strjoin(tests[10].prefix, tests[10].sufix);

    tests[11].prefix = "abc";
    tests[11].sufix = "def";
    tests[11].expected = strdup("abcdef");
    tests[11].result = ft_strjoin(tests[11].prefix, tests[11].sufix);

    tests[12].prefix = "null_prefix";
    tests[12].sufix = NULL;
    tests[12].expected = strdup("null_prefix");
    tests[12].result = ft_strjoin(tests[12].prefix, tests[12].sufix);

    tests[13].prefix = NULL;
    tests[13].sufix = "null_suffix";
    tests[13].expected = strdup("null_suffix");
    tests[13].result = ft_strjoin(tests[13].prefix, tests[13].sufix);

    tests[14].prefix = NULL;
    tests[14].sufix = NULL;
    tests[14].expected = NULL;
    tests[14].result = ft_strjoin(tests[14].prefix, tests[14].sufix);

    tests[15].prefix = "escaped\\";
    tests[15].sufix = "characters";
    tests[15].expected = strdup("escaped\\characters");
    tests[15].result = ft_strjoin(tests[15].prefix, tests[15].sufix);

    tests[16].prefix = "1234567890";
    tests[16].sufix = "0987654321";
    tests[16].expected = strdup("12345678900987654321");
    tests[16].result = ft_strjoin(tests[16].prefix, tests[16].sufix);

    tests[17].prefix = "test";
    tests[17].sufix = "test";
    tests[17].expected = strdup("testtest");
    tests[17].result = ft_strjoin(tests[17].prefix, tests[17].sufix);

    tests[18].prefix = "a";
    tests[18].sufix = "b";
    tests[18].expected = strdup("ab");
    tests[18].result = ft_strjoin(tests[18].prefix, tests[18].sufix);

    tests[19].prefix = "one_two_";
    tests[19].sufix = "three_four";
    tests[19].expected = strdup("one_two_three_four");
    tests[19].result = ft_strjoin(tests[19].prefix, tests[19].sufix);

    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (custom_strcmp(tests[index].result, tests[index].expected) == 0)
        {
            printf("TEST %d ✅\n", index + 1);
        }
        else
        {
            printf("TEST %d ❌\n", index + 1);
            printf("   Test case : sufix = \"%s\" , prefix = \"%s\" \n", tests[index].prefix, tests[index].sufix);
            printf("   Got : \"%s\"\n", tests[index].result);
            printf("   Expected : \"%s\"\n", tests[index].expected);
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
        if(tests[index].expected)   
            free(tests[index].expected);
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