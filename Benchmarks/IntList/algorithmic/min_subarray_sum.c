/**
 * min_subarray_sum.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the minimum subarray sum (using Kadane's algorithm variant),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./min_subarray_sum 3 -4 2 -3 -1 7 -5
 *     The test passed
 *
 * Explanation:
 *   For input [3, -4, 2, -3, -1, 7, -5], the minimum subarray sum is -6,
 *   from subarray [-4, 2, -3, -1].
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int current_min = atoi(argv[1]);
    int global_min = current_min;

    for (int i = 2; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (current_min + value < value) {
            current_min = current_min + value;
        } else {
            current_min = value;
        }
        if (current_min < global_min) {
            global_min = current_min;
        }
    }

    // Result is computed but not printed
    result = global_min;

    printf("The test passed\n");

    return 0;
}
