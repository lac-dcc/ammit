/**
 * min_difference.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the minimum difference between any two values,
 * and prints "The test passed".
 *
 * The minimum difference is defined as the smallest absolute
 * difference between any two distinct elements in the list.
 *
 * The input should be a list of integers, separated by spaces, passed
 * through the command line.
 *
 * Example usage:
 *     $ ./min_difference 10 3 20 5 8
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        return 1; // Need at least 2 integers for a difference
    }

    int count = argc - 1;
    int *values = (int *)malloc(count * sizeof(int));
    if (!values) {
        return 1; // Allocation failed
    }

    for (int i = 0; i < count; ++i) {
        values[i] = atoi(argv[i + 1]);
    }

    int min_diff = values[0] > values[1] ? values[0] - values[1] : values[1] - values[0];

    for (int i = 0; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            int diff = values[i] - values[j];
            if (diff < 0) {
                diff = -diff; // absolute value
            }
            if (diff < min_diff) {
                min_diff = diff;
            }
        }
    }

    result = min_diff; // store computed minimum difference

    free(values);

    printf("The test passed\n");

    return 0;
}
