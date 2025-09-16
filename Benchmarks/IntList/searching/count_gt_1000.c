/**
 * count_gt_1000.c
 *
 * This program reads a list of integers from argc/argv,
 * counts how many values are greater than 1000, stores the count
 * in the global `result` variable, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./count_gt_1000 10 2000 5000 999 42 1001
 *     The test passed
 *
 * Notes:
 *  - Only allowed libc functions used: printf, atoi.
 *  - The computed result is not printed; only the final message is printed.
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count_gt = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value > 1000) {
            count_gt++;
        }
    }

    // Store result (number of values greater than 1000)
    result = count_gt;

    printf("The test passed\n");

    return 0;
}
