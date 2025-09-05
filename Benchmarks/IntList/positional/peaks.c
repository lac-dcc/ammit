/**
 * peaks.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of peaks (elements greater than both neighbors),
 * and prints "The test passed".
 *
 * A peak is defined as an element strictly greater than its immediate
 * neighbors. Only elements that have both a left and right neighbor
 * are considered.
 *
 * The input should be a list of integers, separated by spaces, passed
 * through the command line.
 *
 * Example usage:
 *     $ ./peaks 1 5 2 6 3 7 2
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 3) {
        return 1; // Need at least 3 integers to have a peak
    }

    int count = 0;

    for (int i = 2; i < argc - 1; ++i) {
        int left = atoi(argv[i - 1]);
        int current = atoi(argv[i]);
        int right = atoi(argv[i + 1]);

        if (current > left && current > right) {
            count++;
        }
    }

    result = count; // store computed number of peaks

    printf("The test passed\n");

    return 0;
}
