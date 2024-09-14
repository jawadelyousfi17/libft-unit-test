#include <stdio.h>
#include <string.h>
#include "../libs/c_strcmp.c"

char *ft_strnstr(const char *big, const char *little, size_t len);
int custom_strcmp(const char *str1, const char *str2);

typedef struct{
    char big[100];
    char little[100];
    size_t len;
    char *expected;
} test_val;

#define TESTS_NBR 40

int main()
{
    test_val tests[TESTS_NBR];

     strcpy(tests[0].big, "Hello 1337");
    strcpy(tests[0].little, "1337");
    tests[0].expected = "1337";
    tests[0].len = 10;

    // Test case 1: First character match
    strcpy(tests[1].big, "Hello 1337");
    strcpy(tests[1].little, "H");
    tests[1].expected = "Hello 1337";
    tests[1].len = 10;

    // Test case 2: Partial match
    strcpy(tests[2].big, "Hello World!");
    strcpy(tests[2].little, "World");
    tests[2].expected = "World!";
    tests[2].len = 11;

    // Test case 3: No match
    strcpy(tests[3].big, "Hello World!");
    strcpy(tests[3].little, "42");
    tests[3].expected = NULL;
    tests[3].len = 11;

    // Test case 4: Empty little string
    strcpy(tests[4].big, "Hello World!");
    strcpy(tests[4].little, "");
    tests[4].expected = "Hello World!";
    tests[4].len = 11;

    // Test case 5: Empty big string
    strcpy(tests[5].big, "");
    strcpy(tests[5].little, "World");
    tests[5].expected = NULL;
    tests[5].len = 10;

    // Test case 6: Both strings empty
    strcpy(tests[6].big, "");
    strcpy(tests[6].little, "");
    tests[6].expected = "";
    tests[6].len = 0;

    // Test case 7: Case sensitivity
    strcpy(tests[7].big, "Hello World!");
    strcpy(tests[7].little, "world");
    tests[7].expected = NULL;
    tests[7].len = 12;

    // Test case 8: Match at the end
    strcpy(tests[8].big, "123456789Hello");
    strcpy(tests[8].little, "Hello");
    tests[8].expected = "Hello";
    tests[8].len = 15;

    // Test case 9: Substring larger than length
    strcpy(tests[9].big, "Hello 1337");
    strcpy(tests[9].little, "1337");
    tests[9].expected = NULL;
    tests[9].len = 5;

    // Test case 10: Match with one character
    strcpy(tests[10].big, "A");
    strcpy(tests[10].little, "A");
    tests[10].expected = "A";
    tests[10].len = 1;

    // Test case 11: Match with special characters
    strcpy(tests[11].big, "!@#$%^&*()");
    strcpy(tests[11].little, "$%^");
    tests[11].expected = "$%^&*()";
    tests[11].len = 10;

    // Test case 12: Long strings
    strcpy(tests[12].big, "This is a very long string for testing the strnstr function.");
    strcpy(tests[12].little, "testing");
    tests[12].expected = "testing the strnstr function.";
    tests[12].len = 50;

    // Test case 13: No match due to case difference
    strcpy(tests[13].big, "HelloWorld");
    strcpy(tests[13].little, "hello");
    tests[13].expected = NULL;
    tests[13].len = 10;

    // Test case 14: Searching with very small len
    strcpy(tests[14].big, "abcdef");
    strcpy(tests[14].little, "cd");
    tests[14].expected = NULL;
    tests[14].len = 2;

    // Test case 15: Substring matches partially
    strcpy(tests[15].big, "abcde");
    strcpy(tests[15].little, "bcd");
    tests[15].expected = "bcde";
    tests[15].len = 5;

    // Test case 16: Little string is longer than big string
    strcpy(tests[16].big, "abc");
    strcpy(tests[16].little, "abcdef");
    tests[16].expected = NULL;
    tests[16].len = 6;

    // Test case 17: Search within 0 length
    strcpy(tests[17].big, "Hello 1337");
    strcpy(tests[17].little, "1337");
    tests[17].expected = NULL;
    tests[17].len = 0;

    // Test case 18: Search with len exactly equal to the position of the match
    strcpy(tests[18].big, "Find the match here");
    strcpy(tests[18].little, "match");
    tests[18].expected = "match here";
    tests[18].len = 14;

    // Test case 19: Match at the start
    strcpy(tests[19].big, "HelloWorld");
    strcpy(tests[19].little, "Hello");
    tests[19].expected = "HelloWorld";
    tests[19].len = 10;

    // Test case 20: Repeated substring
    strcpy(tests[20].big, "abcabcabc");
    strcpy(tests[20].little, "abc");
    tests[20].expected = "abcabcabc";
    tests[20].len = 9;

    // Test case 21: Very long little string
    strcpy(tests[21].big, "abcdefg");
    strcpy(tests[21].little, "abcdefghijklmnopqrstuvwxyz");
    tests[21].expected = NULL;
    tests[21].len = 26;

    // Test case 22: Match when both strings are identical
    strcpy(tests[22].big, "match");
    strcpy(tests[22].little, "match");
    tests[22].expected = "match";
    tests[22].len = 5;

    // Test case 23: Trailing whitespace
    strcpy(tests[23].big, "This is a test ");
    strcpy(tests[23].little, "test ");
    tests[23].expected = NULL;
    tests[23].len = 14;

    // Test case 24: Substring at the beginning
    strcpy(tests[24].big, "substring");
    strcpy(tests[24].little, "sub");
    tests[24].expected = "substring";
    tests[24].len = 9;

    // Test case 25: Substring partially matches but cutoff due to len
    strcpy(tests[25].big, "abcdxyz");
    strcpy(tests[25].little, "cdx");
    tests[25].expected = NULL;
    tests[25].len = 4;

    // Test case 26: Match with special symbols
    strcpy(tests[26].big, "#$%^&*(123");
    strcpy(tests[26].little, "&*(");
    tests[26].expected = "&*(123";
    tests[26].len = 9;

    // Test case 27: Only one character matches
    strcpy(tests[27].big, "Hello World");
    strcpy(tests[27].little, "W");
    tests[27].expected = "World";
    tests[27].len = 11;

    // Test case 28: Match when there is only one character left to search
    strcpy(tests[28].big, "abcde");
    strcpy(tests[28].little, "e");
    tests[28].expected = "e";
    tests[28].len = 5;

    // Test case 29: No match due to case sensitivity with different letter cases
    strcpy(tests[29].big, "abcde");
    strcpy(tests[29].little, "E");
    tests[29].expected = NULL;
    tests[29].len = 5;

     // Test case 30: Little string appears after the cutoff length
    strcpy(tests[30].big, "Hello 123456");
    strcpy(tests[30].little, "456");
    tests[30].expected = NULL;
    tests[30].len = 8;

    // Test case 31: Little string spans right at the boundary of len
    strcpy(tests[31].big, "Boundary test");
    strcpy(tests[31].little, "test");
    tests[31].expected = NULL; // len cuts off the match
    tests[31].len = 9;

    // Test case 32: Big string contains repeating characters, and little string is part of that sequence
    strcpy(tests[32].big, "abababababd");
    strcpy(tests[32].little, "ab");
    tests[32].expected = "abababababd";
    tests[32].len = 10;

    // Test case 33: Big string contains a substring of little, but not a full match
    strcpy(tests[33].big, "prefix123suffix");
    strcpy(tests[33].little, "prefixsuffix");
    tests[33].expected = NULL;
    tests[33].len = 15;

    // Test case 34: Very large len, but little string appears early
    strcpy(tests[34].big, "A quick brown fox");
    strcpy(tests[34].little, "quick");
    tests[34].expected = "quick brown fox";
    tests[34].len = 100;  // len larger than string length

    // Test case 35: len is exactly at the match's ending position
    strcpy(tests[35].big, "abcdefg1234");
    strcpy(tests[35].little, "123");
    tests[35].expected = "1234";
    tests[35].len = 10;

    // Test case 36: Big string is filled with repeating characters, little is a substring of that
    strcpy(tests[36].big, "aaaaaaaaaa");
    strcpy(tests[36].little, "aaa");
    tests[36].expected = "aaaaaaaaaa";
    tests[36].len = 9;

    // Test case 37: Big string ends with the little string, but len is smaller than needed
    strcpy(tests[37].big, "1234567890xyz");
    strcpy(tests[37].little, "xyz");
    tests[37].expected = NULL;  // len cuts off the match
    tests[37].len = 10;

    // Test case 38: Little string is at the beginning but len too short to match fully
    strcpy(tests[38].big, "Hello there");
    strcpy(tests[38].little, "Hello");
    tests[38].expected = NULL;
    tests[38].len = 2;

    // Test case 39: Both strings are equal but len is too small
    strcpy(tests[39].big, "equal");
    strcpy(tests[39].little, "equal");
    tests[39].expected = NULL;
    tests[39].len = 4;




    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (custom_strcmp(ft_strnstr(tests[index].big, tests[index].little , tests[index].len ),tests[index].expected) == 0)
        {
            printf("TEST %d ✅\n",index);
        }
        else 
        {
            printf("TEST %d ❌\n",index);
            printf("   Test case : \"%s\" \"%s\" %ld\n" ,tests[index].big, tests[index].little , tests[index].len);
            printf("   Got : \"%s\"\n" ,ft_strnstr(tests[index].big, tests[index].little , tests[index].len));
            printf("   Expected : \"%s\"\n", tests[index].expected);
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
        printf("FAILD ! %d / %d\n",passed_tests,TESTS_NBR);
    }
    return 1;
}
