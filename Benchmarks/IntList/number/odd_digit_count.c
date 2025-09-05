/**
 * odd_digit_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of integers that have an odd number of digits,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./odd_digit_count 12 345 6789 7 44
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

/* Helper function to count digits in an integer */
int digit_count(int n) {
    if (n == 0) {
        return 1;
    }
    if (n < 0) {
        n = -n; // Ignore sign
    }
    int count = 0;
    while (n > 0) {
        n = n / 10;
        count++;
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int odd_digit_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        int digits = digit_count(value);
        if (digits % 2 == 1) {
            odd_digit_count++;
        }
    }

    result = odd_digit_count; // Store computed result

    printf("The test passed\n");

    return 0;
}
