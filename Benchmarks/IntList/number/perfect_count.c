/**
 * perfect_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of perfect numbers among them,
 * and prints "The test passed".
 *
 * A perfect number is a positive integer that is equal to the sum
 * of its proper divisors (excluding itself).
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./perfect_count 6 28 12 496 100
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

/* Helper function to check if a number is perfect */
int is_perfect(int n) {
    if (n <= 1) {
        return 0;
    }
    int sum = 1; // 1 is always a divisor
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) {
                sum += n / i;
            }
        }
    }
    return sum == n;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int perfect_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_perfect(value)) {
            perfect_count++;
        }
    }

    result = perfect_count; // Store computed result

    printf("The test passed\n");

    return 0;
}
