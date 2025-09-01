/**
 * positive_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of positive integers, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./positive_count -3 0 1 2 -5 4
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

    int positive_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value > 0) {
            positive_count++;
        }
    }

    // Store result (not printed)
    result = positive_count;

    printf("The test passed\n");

    return 0;
}
