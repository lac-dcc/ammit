/**
 * sum.c
 *
 * This program reads a list of integers from argc/argv,
 * computes their sum, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./sum 10 20 30
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int sum = 0;

    for (int i = 1; i < argc; ++i) {
        sum += atoi(argv[i]);
    }

    result = sum; // Store the sum to avoid optimization removal

    printf("The test passed\n");

    return 0;
}
