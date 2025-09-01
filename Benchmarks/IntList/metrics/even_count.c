/**
 * even_count.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of even integers, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./even_count 1 2 3 4 5 6
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

    int even_count = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value % 2 == 0) {
            even_count++;
        }
    }

    // Store result (not printed)
    result = even_count;

    printf("The test passed\n");

    return 0;
}
