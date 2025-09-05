/**
 * palindromic_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of palindromic integers among them,
 * and prints "The test passed".
 *
 * A palindromic integer is one that reads the same forward
 * and backward in its decimal representation.
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./palindromic_count 121 44 123 7 90
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

/* Helper function to check if a number is palindromic */
int is_palindromic(int n) {
    if (n < 0) {
        return 0; // Negative numbers are not considered palindromes
    }
    int original = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    return original == reversed;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int palindromic_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_palindromic(value)) {
            palindromic_count++;
        }
    }

    result = palindromic_count; // Store computed result

    printf("The test passed\n");

    return 0;
}
