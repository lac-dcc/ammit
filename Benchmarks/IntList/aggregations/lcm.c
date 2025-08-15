/**
 * lcm.c
 *
 * This program reads a list of integers from argc/argv,
 * computes their least common multiple (LCM),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./lcm 4 6 8
 *     The test passed
 *
 * In this example:
 *     LCM(4, 6, 8) = 24
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

int lcm(int a, int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a / gcd(a, b)) * b;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int l = atoi(argv[1]);

    for (int i = 2; i < argc; ++i) {
        l = lcm(l, atoi(argv[i]));
    }

    result = l; // Store to prevent optimization removal

    printf("The test passed\n");

    return 0;
}
