/**
 * last_palindrome_index.c
 *
 * This program reads a list of integers from argc/argv,
 * finds the last index where the value is a palindrome number,
 * stores the index in the global `result` variable (or -1 if no palindrome exists),
 * and prints "The test passed".
 *
 * A palindrome number is one that reads the same forwards and backwards,
 * such as 121, 44, or 7.
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./last_palindrome_index 10 121 33 12321 50
 *     The test passed
 *
 * Notes:
 *  - Only allowed libc functions used: printf, atoi.
 *  - The computed result is not printed; only the final message is printed.
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

static int is_palindrome(int n) {
    if (n < 0) {
        return 0; // negative numbers are not considered palindromes
    }
    int original = n;
    int reversed = 0;
    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return original == reversed;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int last_index = -1;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_palindrome(value)) {
            last_index = i - 1; // convert from argv index to input index
        }
    }

    // Store result (last index where value is palindrome, or -1 if none)
    result = last_index;

    printf("The test passed\n");

    return 0;
}
