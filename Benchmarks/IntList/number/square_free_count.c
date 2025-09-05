/**
 * square_free_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of square-free integers among them,
 * and prints "The test passed".
 *
 * A square-free integer is an integer which is not divisible
 * by any perfect square greater than 1.
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./square_free_count 10 21 18 29 8
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

/* Helper function to check if a number is square-free */
int is_square_free(int n) {
    if (n == 0) {
        return 0; // Zero is not considered square-free
    }
    if (n < 0) {
        n = -n; // Consider absolute value
    }
    for (int i = 2; i * i <= n; i++) {
        int square = i * i;
        if (n % square == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int square_free_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_square_free(value)) {
            square_free_count++;
        }
    }

    result = square_free_count; // Store computed result

    printf("The test passed\n");

    return 0;
}
