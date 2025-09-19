/**
 * array_rotated_sorted.c
 *
 * This program reads a list of integers from argc/argv,
 * checks whether the sequence of integers is a rotated sorted array,
 * stores the result (1 if rotated sorted, 0 otherwise) in the global `result`
 * variable, and prints "The test passed".
 *
 * An array is considered rotated sorted if it is non-decreasing and can be
 * rotated at some pivot point to become fully sorted. For example:
 *   [3, 4, 5, 1, 2] is rotated sorted
 *   [1, 2, 3, 4, 5] is also rotated sorted (rotation at position 0)
 *   [2, 1, 3, 4, 5] is not rotated sorted
 *
 * Example usage:
 *     $ ./array_rotated_sorted 3 4 5 1 2
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

    int count_breaks = 0;

    for (int i = 2; i < argc; ++i) {
        int prev = atoi(argv[i - 1]);
        int curr = atoi(argv[i]);
        if (curr < prev) {
            count_breaks++;
        }
    }

    // Also check between last and first for rotation
    int first = atoi(argv[1]);
    int last = atoi(argv[argc - 1]);
    if (first < last) {
        count_breaks++;
    }

    // At most one "break" allowed
    int is_rotated_sorted = (count_breaks <= 1);

    // Store result
    result = is_rotated_sorted;

    printf("The test passed\n");

    return 0;
}
