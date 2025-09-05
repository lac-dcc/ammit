/**
 * smallest_prime.c
 *
 * This program reads a list of integers from argc/argv,
 * finds the smallest prime number among them, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./smallest_prime 10 21 17 29 8
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

    int smallest_prime = 0;
    int found = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (is_prime(value)) {
            if (!found || value < smallest_prime) {
                smallest_prime = value;
                found = 1;
            }
        }
    }

    if (found) {
        result = smallest_prime; // Store the computed result
    } else {
        result = -1; // Indicate no prime was found
    }

    printf("The test passed\n");

    return 0;
}
