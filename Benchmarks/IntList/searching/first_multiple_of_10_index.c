/**
 * first_multiple_of_10_index.c
 *
 * This program reads a list of integers from argc/argv,
 * finds the index of the first value that is a multiple of 10,
 * stores the index in the global `result` variable (or -1 if no such value exists),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./first_multiple_of_10_index 3 7 15 20 25
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

    int found_index = -1;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value % 10 == 0) {
            found_index = i - 1; // convert from argv index to input index
            break;
        }
    }

    // Store result (index of first multiple of 10, or -1 if none)
    result = found_index;

    printf("The test passed\n");

    return 0;
}
