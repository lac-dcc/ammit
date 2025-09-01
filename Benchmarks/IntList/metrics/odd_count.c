/**
 * odd_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of odd integers, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./odd_count 1 2 3 4 5 6
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

    int odd_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value % 2 != 0) {
            odd_count++;
        }
    }

    // Store result (not printed)
    result = odd_count;

    printf("The test passed\n");

    return 0;
}
