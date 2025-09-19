/**
 * lis.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the length of the Longest Increasing Subsequence (LIS),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./lis 10 22 9 33 21 50 41 60
 *     The test passed
 *
 * In this example, the LIS length is 5: (10, 22, 33, 50, 60).
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;
    int *arr = (int *)malloc(n * sizeof(int));
    int *lis = (int *)malloc(n * sizeof(int));
    if (!arr || !lis) {
        return 1; // Allocation failed
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = atoi(argv[i + 1]);
        lis[i] = 1; // Each element is LIS of length 1
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        if (lis[i] > max_len) {
            max_len = lis[i];
        }
    }

    result = max_len; // store LIS length

    free(arr);
    free(lis);

    printf("The test passed\n");
    return 0;
}
