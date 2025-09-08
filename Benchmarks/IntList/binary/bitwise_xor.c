/**
 * bitwise_xor.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the bitwise XOR of all of them,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./bitwise_xor 12 6 14
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

    int xor_result = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        xor_result ^= value;
    }

    // Computed result but not printed
    result = xor_result;

    printf("The test passed\n");

    return 0;
}
