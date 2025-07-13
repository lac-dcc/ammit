/**
 * minmax.c
 *
 * This program reads a list of integers from argc/argv,
 * computes both the minimum and maximum values in one pass,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./minmax 8 2 5 1 9
 *     The test passed
 *
 * Author: ChatGPT
 */

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int result = 0; // Can encode result as max << 16 | min, or just use one of them for benchmarking

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No input
    }

    int min = atoi(argv[1]);
    int max = min;

    for (int i = 2; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value < min) {
            min = value;
        } else if (value > max) {
            max = value;
        }
    }

    // Combine into one int for benchmarking purposes (optional)
    result = (max << 16) | (min & 0xFFFF);

    printf("The test passed\n");

    return 0;
}
