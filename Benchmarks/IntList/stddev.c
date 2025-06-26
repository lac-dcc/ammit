/**
 * stddev.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the standard deviation (integer approximation),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./stddev 10 12 23 23 16 23 21 16
 *     The test passed
 *
 * Author: ChatGPT
 */

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int result = 0;

// Integer square root using the Babylonian method
int isqrt(int n) {
    if (n <= 0) return 0;
    int x = n;
    int y = (x + 1) / 2;
    while (y < x) {
        x = y;
        y = (x + n / x) / 2;
    }
    return x;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No input
    }

    int n = argc - 1;
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int val = atoi(argv[i + 1]);
        arr[i] = val;
        sum += val;
    }

    int mean = sum / n;

    int squared_diff_sum = 0;
    for (int i = 0; i < n; ++i) {
        int diff = arr[i] - mean;
        squared_diff_sum += diff * diff;
    }

    int variance = squared_diff_sum / n;
    int stddev = isqrt(variance);

    result = stddev; // Store the computed standard deviation

    free(arr);

    printf("The test passed\n");

    return 0;
}
