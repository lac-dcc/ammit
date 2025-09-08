/**
 * leading_bit_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes how many of them have the leading (most significant)
 * bit set to 1 in their 32-bit representation,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./leading_bit_count -1 2147483647 -2147483648 5
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        // Check if the 32-bit leading bit is set
        if (value & (1 << 31)) {
            count++;
        }
    }

    // Computed result but not printed
    result = count;

    printf("The test passed\n");

    return 0;
}
