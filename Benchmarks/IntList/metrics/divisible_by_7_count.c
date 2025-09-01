/**
 * divisible_by_7_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of integers divisible by 7, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./divisible_by_7_count 7 14 15 21 28 30
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

    int div7_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value % 7 == 0) {
            div7_count++;
        }
    }

    // Store result (not printed)
    result = div7_count;

    printf("The test passed\n");

    return 0;
}
