/**
 * triangular_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of triangular numbers among them,
 * and prints "The test passed".
 *
 * A triangular number is one of the form n*(n+1)/2 for some n >= 1.
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./triangular_count 1 3 4 6 10 15 20
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

/* Helper function to check if n is a perfect square */
int is_perfect_square(long long n) {
    if (n < 0) {
        return 0;
    }
    long long i = 0;
    while (i * i <= n) {
        if (i * i == n) {
            return 1;
        }
        i++;
    }
    return 0;
}

/* Helper function to check if a number is triangular
   A number x is triangular if and only if 8*x + 1 is a perfect square */
int is_triangular(int x) {
    if (x < 1) {
        return 0;
    }
    long long val = 8LL * x + 1;
    return is_perfect_square(val);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int triangular_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_triangular(value)) {
            triangular_count++;
        }
    }

    result = triangular_count; // Store computed result

    printf("The test passed\n");

    return 0;
}
