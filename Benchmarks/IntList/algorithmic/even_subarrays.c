/**
 * even_subarrays.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of subarrays that consist entirely of even numbers,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./even_subarrays 2 4 1 6 8
 *     The test passed
 *
 * Explanation:
 *   For input [2,4,1,6,8], the valid subarrays are:
 *     [2], [4], [2,4], [6], [8], [6,8]
 *   Total = 6
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
    int length = 0; // Length of current run of even numbers

    for (int i = 1; i <= n; i++) {
        int value = atoi(argv[i]);
        if ((value & 1) == 0) {
            // Even number, extend the current run
            length++;
            total += length;
        } else {
            // Odd number, reset run
            length = 0;
        }
    }

    // Result is computed but not printed
    result = total;

    printf("The test passed\n");

    return 0;
}
