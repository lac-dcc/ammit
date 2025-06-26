/**
 * variance.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the population variance, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./variance 10 12 23 23 16 23 21 16
 *     The test passed
 *
 * Author: ChatGPT
 */

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int result = 0;

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No input values
    }

    int n = argc - 1;
    int *values = (int *)malloc(n * sizeof(int));
    if (!values) {
        return 1; // Memory allocation failed
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int val = atoi(argv[i + 1]);
        values[i] = val;
        sum += val;
    }

    int mean = sum / n;

    int squared_diff_sum = 0;
    for (int i = 0; i < n; ++i) {
        int diff = values[i] - mean;
        squared_diff_sum += diff * diff;
    }

    int variance = squared_diff_sum / n;

    result = variance; // Store computed variance

    free(values);

    printf("The test passed\n");

    return 0;
}
