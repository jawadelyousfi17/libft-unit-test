#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../libs/c_strcmp.c"

char *ft_strdup(const char *s);
int custom_strcmp(const char *str1, const char *str2);

typedef struct{
    char source[100];
    char *dest;
    char *expected;
} test_val;

#define TESTS_NBR 20

int main()
{
    test_val tests[TESTS_NBR];

    strcpy(tests[0].source, "Hello 1337");
    tests[0].dest = ft_strdup(tests[0].source);
    tests[0].expected = tests[0].source;

    // Test case 1: Duplicating a string with special characters
    strcpy(tests[1].source, "!@#$%^&*()");
    tests[1].dest = ft_strdup(tests[1].source);
    tests[1].expected = tests[1].source;

    // Test case 2: Empty string
    strcpy(tests[2].source, "");
    tests[2].dest = ft_strdup(tests[2].source);
    tests[2].expected = tests[2].source;

    // Test case 3: Single character
    strcpy(tests[3].source, "A");
    tests[3].dest = ft_strdup(tests[3].source);
    tests[3].expected = tests[3].source;

    // Test case 4: Long string
    strcpy(tests[4].source, "This is a very long string for testing ft_strdup.");
    tests[4].dest = ft_strdup(tests[4].source);
    tests[4].expected = tests[4].source;

    // Test case 5: String with spaces
    strcpy(tests[5].source, "Hello 1337 World!");
    tests[5].dest = ft_strdup(tests[5].source);
    tests[5].expected = tests[5].source;

    // Test case 6: String with numbers
    strcpy(tests[6].source, "1234567890");
    tests[6].dest = ft_strdup(tests[6].source);
    tests[6].expected = tests[6].source;

    // Test case 7: String with only special characters
    strcpy(tests[7].source, "`~!@#$%^&*()-_=+");
    tests[7].dest = ft_strdup(tests[7].source);
    tests[7].expected = tests[7].source;

    // Test case 8: String with mixed case
    strcpy(tests[8].source, "HelLo WoRLd");
    tests[8].dest = ft_strdup(tests[8].source);
    tests[8].expected = tests[8].source;

    // Test case 9: String with tab characters
    strcpy(tests[9].source, "Hello\tWorld");
    tests[9].dest = ft_strdup(tests[9].source);
    tests[9].expected = tests[9].source;

    // Test case 10: String with newline characters
    strcpy(tests[10].source, "Line1\nLine2");
    tests[10].dest = ft_strdup(tests[10].source);
    tests[10].expected = tests[10].source;

    // Test case 11: String with null characters inside
    strcpy(tests[11].source, "Hello\0World");
    tests[11].dest = ft_strdup(tests[11].source);
    tests[11].expected = tests[11].source;

    // Test case 12: String with repeated characters
    strcpy(tests[12].source, "aaaaaaa");
    tests[12].dest = ft_strdup(tests[12].source);
    tests[12].expected = tests[12].source;

    // Test case 13: String with leading spaces
    strcpy(tests[13].source, "   Leading spaces");
    tests[13].dest = ft_strdup(tests[13].source);
    tests[13].expected = tests[13].source;

    // Test case 14: String with trailing spaces
    strcpy(tests[14].source, "Trailing spaces   ");
    tests[14].dest = ft_strdup(tests[14].source);
    tests[14].expected = tests[14].source;

    // Test case 15: String with leading and trailing spaces
    strcpy(tests[15].source, "   Both sides   ");
    tests[15].dest = ft_strdup(tests[15].source);
    tests[15].expected = tests[15].source;

    // Test case 16: String with emoji characters
    strcpy(tests[16].source, "Hello 🌍😊");
    tests[16].dest = ft_strdup(tests[16].source);
    tests[16].expected = tests[16].source;

    // Test case 17: Empty string with null terminator
    strcpy(tests[17].source, "\0");
    tests[17].dest = ft_strdup(tests[17].source);
    tests[17].expected = tests[17].source;

    // Test case 18: String with Unicode characters
    strcpy(tests[18].source, "こんにちは世界");  // "Hello, World" in Japanese
    tests[18].dest = ft_strdup(tests[18].source);
    tests[18].expected = tests[18].source;

    // Test case 19: String with different encoding characters
    strcpy(tests[19].source, "Olá Mundo!");  // "Hello, World" in Portuguese
    tests[19].dest = ft_strdup(tests[19].source);
    tests[19].expected = tests[19].source;

    
    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (custom_strcmp(tests[index].dest, tests[index].expected) == 0)
        {
            printf("TEST %d ✅\n",index);
        }
        else 
        {
            printf("TEST %d ❌\n",index);
            printf("   Test case : \"%s\" \n" ,tests[index].source);
            printf("   Got : \"%s\"\n" ,tests[index].dest);
            printf("   Expected : \"%s\"\n", tests[index].expected);
            sucess = 0;
            passed_tests--;
        }
        index++;
    }
    //clean
    index = 0;
    // while(index < TESTS_NBR)
    // {
    //     if(tests[index].dest)
    //         free(tests[index].dest);
    //     index++;
    // }
    if (sucess)
    {
        printf("All tests passed ✅\n");
         return 0;
    } else 
    {
        printf("FAILD ! %d / %d\n",passed_tests,TESTS_NBR);
    }
    return 1;
}