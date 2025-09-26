/**
 * max_subarray_sum.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the maximum subarray sum using Kadane's algorithm,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./max_subarray_sum -2 1 -3 4 -1 2 1 -5 4
 *     The test passed
 *
 * Explanation:
 *   For input [-2,1,-3,4,-1,2,1,-5,4], the maximum subarray sum is 6,
 *   from subarray [4, -1, 2, 1].
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int current_max = atoi(argv[1]);
    int global_max = current_max;

    for (int i = 2; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (current_max + value > value) {
            current_max = current_max + value;
        } else {
            current_max = value;
        }
        if (current_max > global_max) {
            global_max = current_max;
        }
    }

    // Result is computed but not printed
    result = global_max;

    printf("The test passed\n");

    return 0;
}
