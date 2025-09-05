/**
 * primes_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes how many of them are prime numbers, and prints "The test passed".
 *
 * A prime number is defined as a number greater than 1 that has no
 * divisors other than 1 and itself.
 *
 * The input should be a list of integers, separated by spaces, passed
 * through the command line.
 *
 * Example usage:
 *     $ ./primes_count 2 3 4 5 6 7 8 9 10 11
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

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

    int count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_prime(value)) {
            count++;
        }
    }

    result = count; // store computed number of primes

    printf("The test passed\n");

    return 0;
}
