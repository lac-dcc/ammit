/**
 * count_100.c
 *
 * This program reads a list of integers from argc/argv,
 * counts how many values are equal to 100, stores the count
 * in the global `result` variable, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./count_100 10 100 50 100 100 7
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

    int count_equal = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value == 100) {
            count_equal++;
        }
    }

    // Store result (number of 100s found)
    result = count_equal;

    printf("The test passed\n");

    return 0;
}
