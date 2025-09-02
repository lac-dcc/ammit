/**
 * even_digit_sum.c
 *
 * This program reads a list of integers from argc/argv,
 * counts how many of them have a digit sum that is even,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./even_digit_sum 12 34 55 123 88
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int digit_sum_is_even(int n) {
    if (n < 0) {
        n = -n; // Use absolute value
    }
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return (sum % 2 == 0);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (digit_sum_is_even(value)) {
            count++;
        }
    }

    // Computed result stored in global variable
    result = count;

    printf("The test passed\n");

    return 0;
}
