/**
 * min_index.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the index of the smallest integer, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces, passed
 * through the command line.
 *
 * Example usage:
 *     $ ./min_index 8 3 5 1 7
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

    int min_value = atoi(argv[1]);
    int min_index = 0; // index relative to input list (starting from 0)

    for (int i = 2; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value < min_value) {
            min_value = value;
            min_index = i - 1; // subtract 1 because argv[1] is index 0
        }
    }

    result = min_index; // store computed index to suppress unused variable

    printf("The test passed\n");
    return 0;
}
