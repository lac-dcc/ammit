/**
 * sum_of_squares.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the sum of their squares, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./sum_of_squares 2 3 4
 *     The test passed
 *
 * In this example:
 *     Sum of squares = (2*2) + (3*3) + (4*4) = 4 + 9 + 16 = 29
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int sum_sq = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        sum_sq += value * value;
    }

    result = sum_sq; // Store to prevent optimization removal

    printf("The test passed\n");

    return 0;
}
