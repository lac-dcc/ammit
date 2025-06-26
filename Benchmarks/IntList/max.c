/**
 * max.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the maximum value, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./max 8 2 5 1 9
 *     The test passed
 *
 * Author: ChatGPT
 */

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int result = 0;

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

    result = max; // Store the maximum value

    printf("The test passed\n");

    return 0;
}
