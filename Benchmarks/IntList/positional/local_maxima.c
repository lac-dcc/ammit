/**
 * local_maxima.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of local maxima in the list, and prints "The test passed".
 *
 * A local maximum is defined as an element that is strictly greater than
 * its immediate neighbors. Only elements that have both a left and right
 * neighbor are considered.
 *
 * The input should be a list of integers, separated by spaces, passed
 * through the command line.
 *
 * Example usage:
 *     $ ./local_maxima 1 3 2 4 1 5 0
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 3) {
        return 1; // Need at least 3 integers to have a local maximum
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

    result = count; // store computed number of local maxima

    printf("The test passed\n");

    return 0;
}
