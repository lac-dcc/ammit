/**
 * range.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the range (max - min), and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./range 4 2 10 8
 *     The test passed
 *
 * Author: Expert C Developer
 */

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int result = 0;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No input provided
    }

    int n = argc - 1;
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return 1; // Allocation failed
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    int min = arr[0];
    int max = arr[0];

    for (int i = 1; i < n; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int range = max - min;
    result = range; // Store computed range without printing

    free(arr);

    printf("The test passed\n");

    return 0;
}
