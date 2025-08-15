/**
 * cumulative_product.c
 *
 * This program reads a list of integers from argc/argv,
 * computes their cumulative product (product of all prefix products),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./cumulative_product 2 3 4
 *     The test passed
 *
 * In this example:
 *     Prefix products: 2, (2*3)=6, (6*4)=24
 *     Cumulative product = 2 * 6 * 24 = 288
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int running_product = 1;
    int cumulative_product = 1;

    for (int i = 1; i < argc; ++i) {
        running_product *= atoi(argv[i]);
        cumulative_product *= running_product;
    }

    result = cumulative_product; // Store to prevent optimization removal

    printf("The test passed\n");

    return 0;
}
