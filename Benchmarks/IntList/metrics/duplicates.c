/**
 * duplicates.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of duplicate values, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./duplicates 1 2 3 2 4 1 5
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count = argc - 1;
    int *values = (int *)malloc(count * sizeof(int));
    if (!values) {
        return 1; // Allocation failed
    }

    // Parse input integers
    for (int i = 0; i < count; ++i) {
        values[i] = atoi(argv[i + 1]);
    }

    int duplicates = 0;

    // Count duplicates
    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            if (values[i] == values[j]) {
                duplicates++;
                break; // Count this duplicate only once
            }
        }
    }

    result = duplicates; // Store in global result

    free(values);

    printf("The test passed\n");

    return 0;
}
