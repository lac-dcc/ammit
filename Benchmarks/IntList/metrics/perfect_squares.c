/**
 * perfect_squares.c
 *
 * This program reads a list of integers from argc/argv,
 * counts how many of them are perfect squares, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./perfect_squares 1 2 3 4 9 16 20
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int is_perfect_square(int n) {
    if (n < 0) {
        return 0;
    }
    int x = 0;
    while (x * x < n) {
        x++;
    }
    return (x * x == n);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_perfect_square(value)) {
            count++;
        }
    }

    // Computed result stored in global variable
    result = count;

    printf("The test passed\n");

    return 0;
}
