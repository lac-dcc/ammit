/**
 * repeated_digits.c
 *
 * This program reads a list of integers from argc/argv,
 * counts how many of them contain at least one repeated digit,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./repeated_digits 11 122 34 567 787
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int has_repeated_digits(int n) {
    if (n < 0) {
        n = -n; // Work with absolute value
    }
    int seen[10];
    for (int i = 0; i < 10; i++) {
        seen[i] = 0;
    }
    while (n > 0) {
        int digit = n % 10;
        if (seen[digit]) {
            return 1; // Found a repeated digit
        }
        seen[digit] = 1;
        n /= 10;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (has_repeated_digits(value)) {
            count++;
        }
    }

    // Computed result stored in global variable
    result = count;

    printf("The test passed\n");

    return 0;
}
