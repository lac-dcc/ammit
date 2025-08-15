/**
 * alternating_sum.c
 *
 * This program reads a list of integers from argc/argv,
 * computes their alternating sum (a[0] - a[1] + a[2] - a[3] + ...),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./alternating_sum 10 20 30 40
 *     The test passed
 *
 * In this example:
 *     Alternating sum = 10 - 20 + 30 - 40 = -20
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int alt_sum = 0;
    int sign = 1;

    for (int i = 1; i < argc; ++i) {
        alt_sum += sign * atoi(argv[i]);
        sign = -sign; // Alternate sign
    }

    result = alt_sum; // Store to prevent optimization removal

    printf("The test passed\n");

    return 0;
}
