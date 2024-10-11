#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/c_strcmp.c"

char **ft_split(char const *s, char c);

void print_array(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
    {
        printf(" --%s-- ", arr[i]);
        i++;
    }
}

int c__assert(char **arr1, char **arr2)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (arr1[j])
        j++;
    while (arr1[i])
        i++;
    if (i != j)
        return (0);
    i = 0;
    while (arr2[i])
    {
        if (custom_strcmp(arr1[i], arr2[i]) != 0)
            return (0);
        i++;
    }
    return (1);
}

typedef struct
{
    char *test_case;
    char split_char;
    char **result;
    char **expected;
} test_vals;

#define TESTS_NBR 22

int main()
{
    test_vals tests[TESTS_NBR];

    // Test case 0
    char *expected0[] = {"Hello", "1337", NULL};
    tests[0].test_case = "Hello 1337";
    tests[0].split_char = ' ';
    tests[0].expected = expected0;
    tests[0].result = ft_split(tests[0].test_case, tests[0].split_char);

    // Test case 1
    char *expected1[] = {"Hello", "1337", NULL};
    tests[1].test_case = "----------Hello--1337---------";
    tests[1].split_char = '-';
    tests[1].expected = expected1;
    tests[1].result = ft_split(tests[1].test_case, tests[1].split_char);

    // Test case 2: Leading space
    char *expected2[] = {"Hello", "world", NULL};
    tests[2].test_case = "        Hello world       ";
    tests[2].split_char = ' ';
    tests[2].expected = expected2;
    tests[2].result = ft_split(tests[2].test_case, tests[2].split_char);

    // Test case 3: Trailing space
    char *expected3[] = {"Welcome", "To", "1337", NULL};
    tests[3].test_case = "WelcomevTov1337";
    tests[3].split_char = 'v';
    tests[3].expected = expected3;
    tests[3].result = ft_split(tests[3].test_case, tests[3].split_char);

    // Test case 4: Multiple delimiters
    char *expected4[] = {"a", "b", "c", "d", "e", NULL};
    tests[4].test_case = "\t\ta\t\t\tb\tc\t\td\t\te\t";
    tests[4].split_char = '\t';
    tests[4].expected = expected4;
    tests[4].result = ft_split(tests[4].test_case, tests[4].split_char);

    // Test case 5: Empty string
    char *expected5[] = {NULL};
    tests[5].test_case = "aaaaaaaaaaaaaaaaaaaaaaaa";
    tests[5].split_char = 'a';
    tests[5].expected = expected5;
    tests[5].result = ft_split(tests[5].test_case, tests[5].split_char);

    // Test case 6: Only delimiters
    char *expected6[] = {"Hello1337!", NULL};
    tests[6].test_case = " Hello1337!";
    tests[6].split_char = ' ';
    tests[6].expected = expected6;
    tests[6].result = ft_split(tests[6].test_case, tests[6].split_char);

    // Test case 7: Consecutive delimiters
    char *expected7[] = {"Hello1337", NULL};
    tests[7].test_case = "Hello1337            ";
    tests[7].split_char = ' ';
    tests[7].expected = expected7;
    tests[7].result = ft_split(tests[7].test_case, tests[7].split_char);

    // Test case 8: Single character input
    char *expected8[] = {"A", NULL};
    tests[8].test_case = "A";
    tests[8].split_char = ' ';
    tests[8].expected = expected8;
    tests[8].result = ft_split(tests[8].test_case, tests[8].split_char);

    // Test case 9: Single delimiter
    char *expected9[] = {"1337 is great school !", NULL};
    tests[9].test_case = "1337 is great school !";
    tests[9].split_char = 'b';
    tests[9].expected = expected9;
    tests[9].result = ft_split(tests[9].test_case, tests[9].split_char);

    // Test case 10: No delimiters
    char *expected10[] = {"HelloWorld", NULL};
    tests[10].test_case = "HelloWorld";
    tests[10].split_char = ' ';
    tests[10].expected = expected10;
    tests[10].result = ft_split(tests[10].test_case, tests[10].split_char);

    // Test case 11: One empty token
    char *expected11[] = {"Hello", "world", NULL};
    tests[11].test_case = "Hello  world";
    tests[11].split_char = ' ';
    tests[11].expected = expected11;
    tests[11].result = ft_split(tests[11].test_case, tests[11].split_char);

    // Test case 12: Special characters
    char *expected12[] = {"Hello", "world!", NULL};
    tests[12].test_case = "Hello,world!";
    tests[12].split_char = ',';
    tests[12].expected = expected12;
    tests[12].result = ft_split(tests[12].test_case, tests[12].split_char);

    // Test case 13: Mixed spaces and delimiters
    char *expected13[] = {"Hello", "world", NULL};
    tests[13].test_case = "Hello  ,  world";
    tests[13].split_char = ',';
    tests[13].expected = expected13;
    tests[13].result = ft_split(tests[13].test_case, tests[13].split_char);

    // Test case 14: Only delimiters with spaces
    char *expected14[] = {NULL};
    tests[14].test_case = "   ";
    tests[14].split_char = ' ';
    tests[14].expected = expected14;
    tests[14].result = ft_split(tests[14].test_case, tests[14].split_char);

    // Test case 15: Delimiter at start
    char *expected15[] = {"world", NULL};
    tests[15].test_case = "-world";
    tests[15].split_char = '-';
    tests[15].expected = expected15;
    tests[15].result = ft_split(tests[15].test_case, tests[15].split_char);

    // Test case 16: Delimiter at end
    char *expected16[] = {"Hello", NULL};
    tests[16].test_case = "Hello-";
    tests[16].split_char = '-';
    tests[16].expected = expected16;
    tests[16].result = ft_split(tests[16].test_case, tests[16].split_char);

    // Test case 17: Mixed delimiters
    char *expected17[] = {"Hello", "world", NULL};
    tests[17].test_case = "Hello-world";
    tests[17].split_char = '-';
    tests[17].expected = expected17;
    tests[17].result = ft_split(tests[17].test_case, tests[17].split_char);

    // Test case 18: Numeric delimiters
    char *expected18[] = {"100", "200", NULL};
    tests[18].test_case = "100,200";
    tests[18].split_char = ',';
    tests[18].expected = expected18;
    tests[18].result = ft_split(tests[18].test_case, tests[18].split_char);

    // Test case 19: Special character delimiter
    char *expected19[] = {"Hello", "world", NULL};
    tests[19].test_case = "Hello@world";
    tests[19].split_char = '@';
    tests[19].expected = expected19;
    tests[19].result = ft_split(tests[19].test_case, tests[19].split_char);

    // Test case 20: Mixed letters and numbers
    char *expected20[] = {"A1", "B2", "C3", NULL};
    tests[20].test_case = "A1 B2 C3";
    tests[20].split_char = ' ';
    tests[20].expected = expected20;
    tests[20].result = ft_split(tests[20].test_case, tests[20].split_char);

    // Test case 21: Trailing delimiters
    char *expected21[] = {"Hello", NULL};
    tests[21].test_case = "Hello---";
    tests[21].split_char = '-';
    tests[21].expected = expected21;
    tests[21].result = ft_split(tests[21].test_case, tests[21].split_char);

    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {

        if (c__assert(tests[index].result, tests[index].expected))
        {
            printf("TEST %d ✅\n", index + 1);
        }
        else
        {
            printf("TEST %d ❌\n", index + 1);
            printf("   Test case : \"%s\" \"%c\" \n", tests[index].test_case, tests[index].split_char);
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
        {
            int j = 0;
            while (tests[index].result[j])
            {
                free(tests[index].result[j]);
                j++;
            }
            free(tests[index].result);
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
        printf("FAILD ! %d / %d\n", passed_tests, TESTS_NBR);
    }
    return 1;
}