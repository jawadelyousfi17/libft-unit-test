#include <stdio.h>
#include <bsd/string.h>
#include "../libs/c_strcmp.c"


int custom_strcmp(const char *str1, const char *str2);
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);

typedef struct{
    char source[100];
    char dest[100];
    char expected[100];
    char holder[100];
    size_t size;
    size_t expected_size;
    size_t destsize;
} test_val;

#define TESTS_NBR 20

int main()
{
   test_val tests[TESTS_NBR];

   strcpy(tests[0].source , "Hello 1337");
   strcpy(tests[0].dest , " are you okay ?");
    strcpy(tests[0].holder, " are you okay ?");
    strcpy(tests[0].expected , " are you okay ?");
    tests[0].destsize = 20;
    tests[0].size = ft_strlcat(tests[0].dest, tests[0].source, tests[0].destsize);
    tests[0].expected_size = strlcat(tests[0].expected, tests[0].source, tests[0].destsize);


    strcpy(tests[1].source , "Hello 1337");
   strcpy(tests[1].dest , " are you okay ?");
    strcpy(tests[1].holder, " are you okay ?");
    strcpy(tests[1].expected , " are you okay ?");
    tests[1].destsize = 4;
    tests[1].size = ft_strlcat(tests[1].dest, tests[1].source, tests[1].destsize);
    tests[1].expected_size = strlcat(tests[1].expected, tests[1].source, tests[1].destsize);


    strcpy(tests[2].source , "");
    strcpy(tests[2].dest , "Destination");
    strcpy(tests[2].holder, "Destination");
    strcpy(tests[2].expected , "Destination");
    tests[2].destsize = 20;
    tests[2].size = ft_strlcat(tests[2].dest, tests[2].source, tests[2].destsize);
    tests[2].expected_size = strlcat(tests[2].expected, tests[2].source, tests[2].destsize);

    // Test case 3: Empty dest
    strcpy(tests[3].source , "Source");
    strcpy(tests[3].dest , "");
    strcpy(tests[3].holder, "");
    strcpy(tests[3].expected , "");
    tests[3].destsize = 10;
    tests[3].size = ft_strlcat(tests[3].dest, tests[3].source, tests[3].destsize);
    tests[3].expected_size = strlcat(tests[3].expected, tests[3].source, tests[3].destsize);

    // Test case 4: destsize smaller than total length (source + dest)
    strcpy(tests[4].source , "World!");
    strcpy(tests[4].dest , "Hello, ");
    strcpy(tests[4].holder, "Hello, ");
    strcpy(tests[4].expected , "Hello, ");
    tests[4].destsize = 10;
    tests[4].size = ft_strlcat(tests[4].dest, tests[4].source, tests[4].destsize);
    tests[4].expected_size = strlcat(tests[4].expected, tests[4].source, tests[4].destsize);

    // Test case 5: destsize exactly equal to combined length of dest + source
    strcpy(tests[5].source , "World!");
    strcpy(tests[5].dest , "Hello, ");
    strcpy(tests[5].holder, "Hello, ");
    strcpy(tests[5].expected , "Hello, ");
    tests[5].destsize = 13;
    tests[5].size = ft_strlcat(tests[5].dest, tests[5].source, tests[5].destsize);
    tests[5].expected_size = strlcat(tests[5].expected, tests[5].source, tests[5].destsize);

    // Test case 6: Empty source and destsize is 0
    strcpy(tests[6].source , "");
    strcpy(tests[6].dest , "Destination");
    strcpy(tests[6].holder, "Destination");
    strcpy(tests[6].expected , "Destination");
    tests[6].destsize = 0;
    tests[6].size = ft_strlcat(tests[6].dest, tests[6].source, tests[6].destsize);
    tests[6].expected_size = strlcat(tests[6].expected, tests[6].source, tests[6].destsize);

    // Test case 7: Very small buffer for destsize
    strcpy(tests[7].source , "World");
    strcpy(tests[7].dest , "Hi");
    strcpy(tests[7].holder, "Hi");
    strcpy(tests[7].expected , "Hi");
    tests[7].destsize = 1;
    tests[7].size = ft_strlcat(tests[7].dest, tests[7].source, tests[7].destsize);
    tests[7].expected_size = strlcat(tests[7].expected, tests[7].source, tests[7].destsize);

    // Test case 8: dest contains null characters inside
    strcpy(tests[8].source , "World");
    strcpy(tests[8].dest , "Hel\0lo");
    strcpy(tests[8].holder, "Hel\0lo");
    strcpy(tests[8].expected , "Hel\0lo");
    tests[8].destsize = 10;
    tests[8].size = ft_strlcat(tests[8].dest, tests[8].source, tests[8].destsize);
    tests[8].expected_size = strlcat(tests[8].expected, tests[8].source, tests[8].destsize);

    // Test case 9: source contains null characters inside
    strcpy(tests[9].source , "Wor\0ld");
    strcpy(tests[9].dest , "Hello");
    strcpy(tests[9].holder, "Hello");
    strcpy(tests[9].expected , "Hello");
    tests[9].destsize = 15;
    tests[9].size = ft_strlcat(tests[9].dest, tests[9].source, tests[9].destsize);
    tests[9].expected_size = strlcat(tests[9].expected, tests[9].source, tests[9].destsize);

    // Test case 10: Source larger than destsize
strcpy(tests[10].source , "Large source string");
strcpy(tests[10].dest , "Small");
strcpy(tests[10].holder, "Small");
strcpy(tests[10].expected , "Small");
tests[10].destsize = 8;
tests[10].size = ft_strlcat(tests[10].dest, tests[10].source, tests[10].destsize);
tests[10].expected_size = strlcat(tests[10].expected, tests[10].source, tests[10].destsize);

// Test case 11: Source fits exactly within the available dest buffer
strcpy(tests[11].source , " fits!");
strcpy(tests[11].dest , "This");
strcpy(tests[11].holder, "This");
strcpy(tests[11].expected , "This");
tests[11].destsize = 12;
tests[11].size = ft_strlcat(tests[11].dest, tests[11].source, tests[11].destsize);
tests[11].expected_size = strlcat(tests[11].expected, tests[11].source, tests[11].destsize);

// Test case 12: destsize smaller than length of dest
strcpy(tests[12].source , "Test");
strcpy(tests[12].dest , "Destination");
strcpy(tests[12].holder, "Destination");
strcpy(tests[12].expected , "Destination");
tests[12].destsize = 5;
tests[12].size = ft_strlcat(tests[12].dest, tests[12].source, tests[12].destsize);
tests[12].expected_size = strlcat(tests[12].expected, tests[12].source, tests[12].destsize);

// Test case 13: Very large source and destsize
strcpy(tests[13].source , "Super long string to test large buffer");
strcpy(tests[13].dest , "Beginning of destination ");
strcpy(tests[13].holder, "Beginning of destination ");
strcpy(tests[13].expected , "Beginning of destination ");
tests[13].destsize = 100;
tests[13].size = ft_strlcat(tests[13].dest, tests[13].source, tests[13].destsize);
tests[13].expected_size = strlcat(tests[13].expected, tests[13].source, tests[13].destsize);

// Test case 14: Source longer than dest, but destsize is small
strcpy(tests[14].source , "Source is long");
strcpy(tests[14].dest , "Dest");
strcpy(tests[14].holder, "Dest");
strcpy(tests[14].expected , "Dest");
tests[14].destsize = 10;
tests[14].size = ft_strlcat(tests[14].dest, tests[14].source, tests[14].destsize);
tests[14].expected_size = strlcat(tests[14].expected, tests[14].source, tests[14].destsize);

// Test case 15: Empty source, very large destsize
strcpy(tests[15].source , "");
strcpy(tests[15].dest , "Dest string");
strcpy(tests[15].holder, "Dest string");
strcpy(tests[15].expected , "Dest string");
tests[15].destsize = 1000;
tests[15].size = ft_strlcat(tests[15].dest, tests[15].source, tests[15].destsize);
tests[15].expected_size = strlcat(tests[15].expected, tests[15].source, tests[15].destsize);

// Test case 16: dest and source are identical
strcpy(tests[16].source , "SameString");
strcpy(tests[16].dest , "SameString");
strcpy(tests[16].holder, "SameString");
strcpy(tests[16].expected , "SameString");
tests[16].destsize = 15;
tests[16].size = ft_strlcat(tests[16].dest, tests[16].source, tests[16].destsize);
tests[16].expected_size = strlcat(tests[16].expected, tests[16].source, tests[16].destsize);

// Test case 17: Large source, tiny destsize
strcpy(tests[17].source , "This source is long");
strcpy(tests[17].dest , "Tiny");
strcpy(tests[17].holder, "Tiny");
strcpy(tests[17].expected , "Tiny");
tests[17].destsize = 3;
tests[17].size = ft_strlcat(tests[17].dest, tests[17].source, tests[17].destsize);
tests[17].expected_size = strlcat(tests[17].expected, tests[17].source, tests[17].destsize);

// Test case 18: Source starts with null character
strcpy(tests[18].source , "\0StartNull");
strcpy(tests[18].dest , "Hello");
strcpy(tests[18].holder, "Hello");
strcpy(tests[18].expected , "Hello");
tests[18].destsize = 15;
tests[18].size = ft_strlcat(tests[18].dest, tests[18].source, tests[18].destsize);
tests[18].expected_size = strlcat(tests[18].expected, tests[18].source, tests[18].destsize);

// Test case 19: Source is null-terminated early
strcpy(tests[19].source , "Null\0Terminated");
strcpy(tests[19].dest , "Test");
strcpy(tests[19].holder, "Test");
strcpy(tests[19].expected , "Test");
tests[19].destsize = 20;
tests[19].size = ft_strlcat(tests[19].dest, tests[19].source, tests[19].destsize);
tests[19].expected_size = strlcat(tests[19].expected, tests[19].source, tests[19].destsize);


    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (custom_strcmp(tests[index].dest, tests[index].expected) == 0 && tests[index].size ==  tests[index].expected_size )
        {
            printf("✅ TEST %d \n",index);
        }
        else 
        {
            printf("\x1b[41m \rTEST %d ❌\x1b[0m\n",index);
            printf("   Test case : \"%s\" \"%s\" %ld \n" ,tests[index].holder,tests[index].source,tests[index].destsize);
            printf("   Got : \"%s\" %ld\n" ,tests[index].dest, tests[index].size );
            printf("   Expected : \"%s\" %ld\n", tests[index].expected , tests[index].expected_size);
            sucess = 0;
            passed_tests--;
        }
        index++;
    }
    if (sucess)
    {
        printf("\n\x1b[46m \r RESULT : All tests passed       ☑️ \x1b[0m\n");
         return 0;
    } else 
    {
        printf("\n\x1b[41m \r RESULT :  FAILD ! %d / %d\x1b[0m\n",passed_tests,TESTS_NBR);
    }
    return 1;
}