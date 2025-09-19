/**
 * array_sorted.c
 *
 * This program reads a list of integers from argc/argv,
 * checks whether the sequence of integers is sorted in non-decreasing order,
 * stores the result (1 if sorted, 0 otherwise) in the global `result`
 * variable, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./array_sorted 1 2 3 4 5
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

    int is_sorted = 1;

    for (int i = 2; i < argc; ++i) {
        int prev = atoi(argv[i - 1]);
        int curr = atoi(argv[i]);
        if (curr < prev) {
            is_sorted = 0;
            break;
        }
    }

    // Store result (1 if sorted, 0 otherwise)
    result = is_sorted;

    printf("The test passed\n");

    return 0;
}
