/**
 * last_even_index.c
 *
 * This program reads a list of integers from argc/argv,
 * finds the index of the last even number, stores the index
 * in the global `result` variable (or -1 if no even number exists),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./last_even_index 3 7 10 5 8
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

    int last_index = -1;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value % 2 == 0) {
            last_index = i - 1; // convert argv index to input index
        }
    }

    // Store result (index of last even number, or -1 if none)
    result = last_index;

    printf("The test passed\n");

    return 0;
}
