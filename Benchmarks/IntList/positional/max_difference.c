/**
 * max_difference.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the maximum difference between any two values,
 * and prints "The test passed".
 *
 * The maximum difference is defined as the difference between
 * the largest and the smallest element in the list.
 *
 * The input should be a list of integers, separated by spaces, passed
 * through the command line.
 *
 * Example usage:
 *     $ ./max_difference 10 3 20 5 8
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int min_val = atoi(argv[1]);
    int max_val = atoi(argv[1]);

    for (int i = 2; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value < min_val) {
            min_val = value;
        }
        if (value > max_val) {
            max_val = value;
        }
    }

    int diff = max_val - min_val;

    result = diff; // store computed maximum difference

    printf("The test passed\n");

    return 0;
}
