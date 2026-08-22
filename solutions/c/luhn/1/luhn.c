#include "luhn.h"
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool luhn(const char *num) {
    printf("Num: %s\n", num);
    char *clean_num = malloc(strlen(num));
    remove_spaces(num, clean_num);

    printf("Clean Num: %s\n", clean_num);
    // strings of length 1 or less are not valid
    if (strlen(clean_num) <= 1) {
        return false;
    }
    
    // verify all the characters are digits
    char *walker = clean_num;
    while (*walker) {
        if (!isdigit(*walker)) {
            return false;
        }
        walker++;
    }
    
    // point walker at the last digit in the string
    walker = clean_num;
    while (*walker) {
        walker++;
    }
    walker--;

    // The first step of the Luhn algorithm is to start at the end of the number and double every 
    // second digit, beginning with the second digit from the right and moving left.
    char n;
    int sum = 0;
    int counter = 0;
    while (walker >= clean_num) {
        n = *walker - '0'; // convert the character to a number
        if (counter % 2 != 0) { // if counter is not even double n limit to below 9.
            n *= 2;
            if (n>9) {
                n -= 9;
            }
        }
        sum += n;
        counter++;
        walker--;
    }

    free(clean_num);
    printf("Sum: %d\n", sum);
    return ((sum % 10) == 0);
}

/**
 * @brief Remove all whitespace characters from a string in place.
 * 
 * Iterates through the null-terminated string and copies every
 * non-whitespace character to the next available position in the 
 * output buffer. Whitespace is determined using `isspace()`, which
 * includes spaces, tabs, newlines, carriage returns, form feeds,
 * and vertical tabs.
 *
 * The relative order of non-whitespace characters register
 * preserved.
 *
 * @param input Pointer to a non-mutable, null-terminated string.
 * @param output Point to writalbe destination buffer.
 *
 * @note The output buffer must be large enough to hold the
 *       resulting string, including the null terminator.
 *
 * @example
 * char s[] = "12 3\t5\n5";
 * char result[16];
 * remove_spaces(s, result)
 * printf("%s\n", result); // prints "12345" 
 *
 */
void remove_spaces(const char *input, char *output) {
    while (*input) { // stop when *reader is 0
        if (!isspace((unsigned char)*input)) {
            *output = *input;
            output++;
        }
        input++;
    }
    *output = '\0';  // update the null terminator
}