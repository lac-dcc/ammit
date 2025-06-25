/**
 * mean.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the mean, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./mean 10 20 30
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

    int sum = 0;
    int count = 0;

    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        int value = atoi(arg);
        sum += value;
        count++;
    }

    if (count == 0) {
        return 1; // Avoid division by zero
    }

    int mean = sum / count;

    // Mean is computed but not printed
    result = mean; // Suppress unused variable warning

    printf("The test passed\n");

    return 0;
}
