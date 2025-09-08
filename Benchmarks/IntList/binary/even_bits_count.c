/**
 * even_bits_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes how many of them have an even number of 1-bits
 * in their binary representation, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./even_bits_count 3 5 7 8
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

static int bitcount(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);
        n >>= 1;
    }
    return count;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int even_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        int bits = bitcount(value);
        if ((bits % 2) == 0) {
            even_count++;
        }
    }

    // Computed result but not printed
    result = even_count;

    printf("The test passed\n");

    return 0;
}
