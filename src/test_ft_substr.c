#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libs/c_strcmp.c"

char *ft_substr(char const *s, unsigned int start, size_t len);

typedef struct
{
    char source[100];
    unsigned int start;
    size_t len;
    char holder[100];
    char *result;
    char *expected;
} test_val;

#define TESTS_NBR 20

int main()
{
    test_val tests[TESTS_NBR];

    // Test 1
    strcpy(tests[0].source, "Hello 1337 how are you ?");
    strcpy(tests[0].holder, tests[0].source);
    tests[0].start = 1;
    tests[0].len = 24;
    tests[0].result = ft_substr(tests[0].source, tests[0].start, tests[0].len);
    tests[0].expected = strdup("ello 1337 how are you ?");

    // Test 2
    strcpy(tests[1].source, "Substring function test");
    strcpy(tests[1].holder, tests[1].source);
    tests[1].start = 0;
    tests[1].len = 9;
    tests[1].result = ft_substr(tests[1].source, tests[1].start, tests[1].len);
    tests[1].expected = strdup("Substring");

    // Test 3
    strcpy(tests[2].source, "C programming");
    strcpy(tests[2].holder, tests[2].source);
    tests[2].start = 2;
    tests[2].len = 11;
    tests[2].result = ft_substr(tests[2].source, tests[2].start, tests[2].len);
    tests[2].expected = strdup("programming");

    // Test 4
    strcpy(tests[3].source, "ft_substr test");
    strcpy(tests[3].holder, tests[3].source);
    tests[3].start = 8;
    tests[3].len = 4;
    tests[3].result = ft_substr(tests[3].source, tests[3].start, tests[3].len);
    tests[3].expected = strdup("r te");

    // Test 5
    strcpy(tests[4].source, "Short string");
    strcpy(tests[4].holder, tests[4].source);
    tests[4].start = 6;
    tests[4].len = 6;
    tests[4].result = ft_substr(tests[4].source, tests[4].start, tests[4].len);
    tests[4].expected = strdup("string");

    // Test 6
    strcpy(tests[5].source, "Boundary test");
    strcpy(tests[5].holder, tests[5].source);
    tests[5].start = 11;
    tests[5].len = 5;
    tests[5].result = ft_substr(tests[5].source, tests[5].start, tests[5].len);
    tests[5].expected = strdup("st");

    // Test 7
    strcpy(tests[6].source, "Edge case test");
    strcpy(tests[6].holder, tests[6].source);
    tests[6].start = 0;
    tests[6].len = 0;
    tests[6].result = ft_substr(tests[6].source, tests[6].start, tests[6].len);
    tests[6].expected = strdup("");

    // Test 8
    strcpy(tests[7].source, "Another example");
    strcpy(tests[7].holder, tests[7].source);
    tests[7].start = 4;
    tests[7].len = 7;
    tests[7].result = ft_substr(tests[7].source, tests[7].start, tests[7].len);
    tests[7].expected = strdup("her exa");

    // Test 9
    strcpy(tests[8].source, "Quick brown fox");
    strcpy(tests[8].holder, tests[8].source);
    tests[8].start = 10;
    tests[8].len = 10;
    tests[8].result = ft_substr(tests[8].source, tests[8].start, tests[8].len);
    tests[8].expected = strdup("n fox");

    // Test 10
    strcpy(tests[9].source, "abc");
    strcpy(tests[9].holder, tests[9].source);
    tests[9].start = 1;
    tests[9].len = 2;
    tests[9].result = ft_substr(tests[9].source, tests[9].start, tests[9].len);
    tests[9].expected = strdup("bc");

    // Test 11
    strcpy(tests[10].source, "Empty string");
    strcpy(tests[10].holder, tests[10].source);
    tests[10].start = 0;
    tests[10].len = 12;
    tests[10].result = ft_substr(tests[10].source, tests[10].start, tests[10].len);
    tests[10].expected = strdup("Empty string");

    // Test 12
    strcpy(tests[11].source, "ft_substr");
    strcpy(tests[11].holder, tests[11].source);
    tests[11].start = 0;
    tests[11].len = 8;
    tests[11].result = ft_substr(tests[11].source, tests[11].start, tests[11].len);
    tests[11].expected = strdup("ft_subst");

    // Test 13
    strcpy(tests[12].source, "Boundary");
    strcpy(tests[12].holder, tests[12].source);
    tests[12].start = 8;
    tests[12].len = 3;
    tests[12].result = ft_substr(tests[12].source, tests[12].start, tests[12].len);
    tests[12].expected = strdup("");

    // Test 14
    strcpy(tests[13].source, "Very long string test");
    strcpy(tests[13].holder, tests[13].source);
    tests[13].start = 5;
    tests[13].len = 10;
    tests[13].result = ft_substr(tests[13].source, tests[13].start, tests[13].len);
    tests[13].expected = strdup("long strin");

    // Test 15
    strcpy(tests[14].source, "Negative start");
    strcpy(tests[14].holder, tests[14].source);
    tests[14].start = 0;
    tests[14].len = 15;
    tests[14].result = ft_substr(tests[14].source, tests[14].start, tests[14].len);
    tests[14].expected = strdup("Negative start");

    // Test 16
    strcpy(tests[15].source, "ft_substr edge case");
    strcpy(tests[15].holder, tests[15].source);
    tests[15].start = 11;
    tests[15].len = 5;
    tests[15].result = ft_substr(tests[15].source, tests[15].start, tests[15].len);
    tests[15].expected = strdup("dge c");

    // Test 17
    strcpy(tests[16].source, "ft_substr edge case");
    strcpy(tests[16].holder, tests[16].source);
    tests[16].start = 16;
    tests[16].len = 3;
    tests[16].result = ft_substr(tests[16].source, tests[16].start, tests[16].len);
    tests[16].expected = strdup("ase");

    // Test 18
    strcpy(tests[17].source, "substring nothing!");
    strcpy(tests[17].holder, tests[17].source);
    tests[17].start = 18;
    tests[17].len = 8;
    tests[17].result = ft_substr(tests[17].source, tests[17].start, tests[17].len);
    tests[17].expected = strdup("");    

    // Test 19
    strcpy(tests[18].source, "substring me!");
    strcpy(tests[18].holder, tests[18].source);
    tests[18].start = 10;
    tests[18].len = 2;
    tests[18].result = ft_substr(tests[18].source, tests[18].start, tests[18].len);
    tests[18].expected = strdup("me");   

    // Test 120
    strcpy(tests[19].source, "substring me, and me too :)");
    strcpy(tests[19].holder, tests[19].source);
    tests[19].start = 10;
    tests[19].len = 19;
    tests[19].result = ft_substr(tests[19].source, tests[19].start, tests[19].len);
    tests[19].expected = strdup("me, and me too :)"); 

    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (custom_strcmp(tests[index].result, tests[index].expected) == 0 && custom_strcmp(tests[index].source, tests[index].holder) == 0)
        {
            printf("TEST %d ✅\n", index + 1);
        }
        else
        {
            printf("TEST %d ❌\n", index + 1);
            printf("   Test case : \"%s\" , start =  %d , len = %ld \n", tests[index].source, tests[index].start, tests[index].len);
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
        if (tests[index].result)
            free(tests[index].result);
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
