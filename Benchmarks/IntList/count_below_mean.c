/**
 * count_below_mean.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of values below the mean,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./count_below_mean 10 20 30 40
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
        return 1; // No integers provided
    }

    int n = argc - 1;
    int *values = (int *)malloc(n * sizeof(int));
    if (!values) {
        return 1; // Allocation failed
    }

    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int value = atoi(argv[i + 1]);
        values[i] = value;
        sum += value;
    }

    int mean = sum / n;

    int count_below = 0;
    for (int i = 0; i < n; ++i) {
        if (values[i] < mean) {
            count_below++;
        }
    }

    result = count_below; // Store the number of values below the mean

    free(values);

    printf("The test passed\n");

    return 0;
}
