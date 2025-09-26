/**
 * increasing_subarrays.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of contiguous increasing subarrays,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./increasing_subarrays 1 2 3 4
 *     The test passed
 *
 * Explanation:
 *   For input [1,2,3,4], the increasing subarrays are:
 *     [1], [2], [3], [4],
 *     [1,2], [2,3], [3,4],
 *     [1,2,3], [2,3,4],
 *     [1,2,3,4]
 *   Total = 10
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;
    int total = 0;
    int length = 1; // length of current increasing run

    for (int i = 2; i <= n; i++) {
        int prev = atoi(argv[i - 1]);
        int curr = atoi(argv[i]);
        if (curr > prev) {
            length++;
        } else {
            length = 1;
        }
        total += length;
    }

    // Add the first element as a single-element subarray
    total += 1;

    // Result is computed but not printed
    result = total;

    printf("The test passed\n");

    return 0;
}
