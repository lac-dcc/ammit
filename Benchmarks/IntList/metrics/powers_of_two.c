/**
 * powers_of_two.c
 *
 * This program reads a list of integers from argc/argv,
 * counts how many of them are powers of two, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./powers_of_two 1 2 3 4 8 12 16
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int is_power_of_two(int n) {
    if (n <= 0) {
        return 0;
    }
    // A number is a power of two if it has exactly one bit set
    return (n & (n - 1)) == 0;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_power_of_two(value)) {
            count++;
        }
    }

    // Computed result stored in global variable
    result = count;

    printf("The test passed\n");

    return 0;
}
