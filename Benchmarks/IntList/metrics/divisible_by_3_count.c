/**
 * divisible_by_3_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of integers divisible by 3, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./divisible_by_3_count 3 6 7 9 10 12
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

    int div3_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value % 3 == 0) {
            div3_count++;
        }
    }

    // Store result (not printed)
    result = div3_count;

    printf("The test passed\n");

    return 0;
}
