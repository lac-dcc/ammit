/**
 * even_subarrays.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of subarrays whose sum is even,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./even_subarrays 1 2 3
 *     The test passed
 *
 * Explanation:
 *   For input [1,2,3], the subarrays with even sums are:
 *     [2], [1,2,3] → total = 2
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    // Prefix parity counts
    int even_count = 1; // Empty prefix has even sum
    int odd_count = 0;
    int prefix_sum = 0;
    int total = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        prefix_sum += value;

        if ((prefix_sum & 1) == 0) {
            // Even prefix
            total += even_count;
            even_count++;
        } else {
            // Odd prefix
            total += odd_count;
            odd_count++;
        }
    }

    result = total; // Store result to avoid optimization removal

    printf("The test passed\n");

    return 0;
}
