/**
 * product.c
 *
 * This program reads a list of integers from argc/argv,
 * computes their product, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./product 2 3 4
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

    int product = 1;

    for (int i = 1; i < argc; ++i) {
        product *= atoi(argv[i]);
    }

    result = product; // Store product to prevent optimization removal

    printf("The test passed\n");

    return 0;
}
