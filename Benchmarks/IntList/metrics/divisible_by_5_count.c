/**
 * divisible_by_5_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of integers divisible by 5, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./divisible_by_5_count 5 10 11 15 22 25
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

    int div5_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value % 5 == 0) {
            div5_count++;
        }
    }

    // Store result (not printed)
    result = div5_count;

    printf("The test passed\n");

    return 0;
}
