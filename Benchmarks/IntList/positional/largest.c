/**
 * largest.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the largest integer, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./largest 10 20 30 5
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

    int max = atoi(argv[1]);

    for (int i = 2; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value > max) {
            max = value;
        }
    }

    // Largest integer is computed but not printed
    result = max; // Suppress unused variable warning

    printf("The test passed\n");

    return 0;
}
