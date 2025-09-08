/**
 * hamming_weight_sum.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the sum of all integers, then computes the
 * Hamming weight (number of 1-bits) of that sum,
 * and finally prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./hamming_weight_sum 3 5 7
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

    int sum = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        sum += value;
    }

    int hamming = bitcount(sum);

    // Computed result but not printed
    result = hamming;

    printf("The test passed\n");

    return 0;
}
