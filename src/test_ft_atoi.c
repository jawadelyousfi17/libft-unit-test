#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

int ft_atoi(char *str);

typedef struct{
    char test[100];
    int expected;
} test_val;

#define TESTS_NBR 30

int main() {
    test_val tests[TESTS_NBR];

    strcpy(tests[0].test, "123456789");
    tests[0].expected = atoi("123456789");

    strcpy(tests[1].test, "0");
    tests[1].expected = atoi("0");

    strcpy(tests[2].test, "-123456");
    tests[2].expected = atoi("-123456");

    strcpy(tests[3].test, "2147483647");  // INT_MAX
    tests[3].expected = atoi("2147483647");

    strcpy(tests[4].test, "-2147483648"); // INT_MIN
    tests[4].expected = atoi("-2147483648");

    strcpy(tests[5].test, "  1234");      // Leading spaces
    tests[5].expected = atoi("  1234");

    strcpy(tests[6].test, "12abc34");     // Mixed with characters (invalid input)
    tests[6].expected = atoi("12abc34");

    strcpy(tests[7].test, "+456");        // Positive number with plus sign
    tests[7].expected = atoi("+456");

    strcpy(tests[8].test, "    -789");    // Leading spaces with negative number
    tests[8].expected = atoi("    -789");

    strcpy(tests[9].test, "      +123456789012  *---"); // Number larger than INT_MAX
    tests[9].expected = atoi("      +123456789012  *---");

    strcpy(tests[10].test, "42abc123");   // Alphanumeric with number at the beginning
    tests[10].expected = atoi("42abc123");

    strcpy(tests[11].test, "");           // Empty string
    tests[11].expected = atoi("");

    strcpy(tests[12].test, "00001234");   // Number with leading zeros
    tests[12].expected = atoi("00001234");

    strcpy(tests[13].test, "   000");     // Only zeros with leading spaces
    tests[13].expected = atoi("   000");

    strcpy(tests[14].test, "9");          // Single digit number
    tests[14].expected = atoi("9");

    strcpy(tests[15].test, "-9");         // Single digit negative number
    tests[15].expected = atoi("-9");

    strcpy(tests[16].test, "123 456");    // Space in the middle
    tests[16].expected = atoi("123");

    strcpy(tests[17].test, "\t1234");     // Leading tab
    tests[17].expected = atoi("\t1234");

    strcpy(tests[18].test, "\n9876");     // Leading newline
    tests[18].expected = atoi("\n9876");

    strcpy(tests[19].test, "0000000000"); // Many leading zeros
    tests[19].expected = atoi("0000000000");

    strcpy(tests[20].test, "-0");         // Negative zero
    tests[20].expected = atoi("-0");

    strcpy(tests[21].test, "1234xyz");    // Number with characters at the end
    tests[21].expected = atoi("1234xyz");

    strcpy(tests[22].test, "12-34");      // Number with hyphen in the middle
    tests[22].expected = atoi("12-34");

    strcpy(tests[23].test, "  -42xyz");   // Leading space, negative number, characters at end
    tests[23].expected = atoi("  -42xyz");

    strcpy(tests[24].test, "+000");       // Positive zero with leading zeros
    tests[24].expected = atoi("+000");

    strcpy(tests[25].test, "+2147483648"); // Overflow beyond INT_MAX
    tests[25].expected = atoi("+2147483648");

    strcpy(tests[26].test, "-2147483649"); // Underflow beyond INT_MIN
    tests[26].expected = atoi("-2147483649");

    strcpy(tests[27].test, "   2147ab483"); // Mixed with letters in the middle of a number
    tests[27].expected = atoi("   2147ab483");

    strcpy(tests[28].test, "100000000000000"); // Large number exceeding limits
    tests[28].expected = atoi("100000000000000");

    strcpy(tests[29].test, "4294967295"); // Number larger than 32-bit unsigned int max
    tests[29].expected = atoi("4294967295");

    int index = 0;
    int sucess = 1;
    int passed_tests = TESTS_NBR;
    while (index < TESTS_NBR)
    {
        if (ft_atoi(tests[index].test) == tests[index].expected)
        {
            printf("TEST %d ✅\n",index + 1);
        }
        else 
        {
            printf("TEST %d ❌\n",index + 1);
                        printf("   Test case : \"%s\"\n" ,tests[index].test);
            printf("   Got : %d\n" ,ft_atoi(tests[index].test));
            printf("   Expected : %d\n", tests[index].expected);
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
        printf("FAILDE ! %d / %d\n",passed_tests,TESTS_NBR);
    }
    return 1;
}