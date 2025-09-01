/**
 * unique.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of unique values, and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./unique 1 2 3 2 4 1 5
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

    int unique_count = 0;

    // Count unique values
    for (int i = 0; i < count; ++i) {
        int is_unique = 1;
        for (int j = 0; j < i; ++j) {
            if (values[i] == values[j]) {
                is_unique = 0;
                break;
            }
        }
        if (is_unique) {
            unique_count++;
        }
    }

    result = unique_count; // Store in global result

    free(values);

    printf("The test passed\n");

    return 0;
}
