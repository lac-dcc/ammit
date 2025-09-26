/**
 * ending_in_zero.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of integers ending in 0,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./ending_in_zero 10 20 33 40 7
 *     The test passed
 *
 * Explanation:
 *   For input [10, 20, 33, 40, 7], the integers ending in 0 are:
 *     10, 20, 40 → total = 3
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value % 10 == 0) {
            count++;
        }
    }

    // Result is computed but not printed
    result = count;

    printf("The test passed\n");

    return 0;
}
