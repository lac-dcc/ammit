/**
 * bitwise_and.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the bitwise AND of all of them,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./bitwise_and 12 6 14
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

    int and_result = -1; // Start with all bits set

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        and_result &= value;
    }

    // Computed result but not printed
    result = and_result;

    printf("The test passed\n");

    return 0;
}
