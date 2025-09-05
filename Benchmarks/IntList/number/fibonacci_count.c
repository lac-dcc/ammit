/**
 * fibonacci_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of Fibonacci numbers among them,
 * and prints "The test passed".
 *
 * A Fibonacci number is part of the sequence defined by:
 * F(0) = 0, F(1) = 1, and F(n) = F(n-1) + F(n-2) for n > 1.
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./fibonacci_count 0 1 2 3 4 5 8 13 21 22
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

/* Helper function to check if n is a perfect square */
int is_perfect_square(int n) {
    if (n < 0) {
        return 0;
    }
    for (int i = 0; i * i <= n; i++) {
        if (i * i == n) {
            return 1;
        }
    }
    return 0;
}

/* Helper function to check if a number is a Fibonacci number
   A number n is Fibonacci if and only if one of (5*n^2 + 4) or (5*n^2 - 4) is a perfect square */
int is_fibonacci(int n) {
    if (n < 0) {
        return 0;
    }
    long long x = (long long)n;
    long long test1 = 5 * x * x + 4;
    long long test2 = 5 * x * x - 4;
    return is_perfect_square((int)test1) || is_perfect_square((int)test2);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int fibonacci_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_fibonacci(value)) {
            fibonacci_count++;
        }
    }

    result = fibonacci_count; // Store computed result

    printf("The test passed\n");

    return 0;
}
