/**
 * gcd.c
 *
 * This program reads a list of integers from argc/argv,
 * computes their greatest common divisor (GCD),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./gcd 48 60 90
 *     The test passed
 *
 * In this example:
 *     GCD(48, 60, 90) = 6
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int g = atoi(argv[1]);

    for (int i = 2; i < argc; ++i) {
        g = gcd(g, atoi(argv[i]));
    }

    result = g; // Store to prevent optimization removal

    printf("The test passed\n");

    return 0;
}
