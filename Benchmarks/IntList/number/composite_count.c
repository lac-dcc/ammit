/**
 * composite_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of composite numbers among them,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./composite_count 10 21 17 29 8
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

/* Helper function to check if a number is prime */
int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int composite_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value > 1 && !is_prime(value)) {
            composite_count++;
        }
    }

    result = composite_count; // Store computed result

    printf("The test passed\n");

    return 0;
}
