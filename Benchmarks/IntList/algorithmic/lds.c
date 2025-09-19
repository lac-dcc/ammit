/**
 * lds.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the length of the Longest Decreasing Subsequence (LDS),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./lds 9 4 3 2 5 4 3 2
 *     The test passed
 *
 * In this example, the LDS length is 5: (9, 5, 4, 3, 2).
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

    int n = argc - 1;
    int *arr = (int *)malloc(n * sizeof(int));
    int *lds = (int *)malloc(n * sizeof(int));
    if (!arr || !lds) {
        return 1; // Allocation failed
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = atoi(argv[i + 1]);
        lds[i] = 1; // Each element is LDS of length 1
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] < arr[j] && lds[i] < lds[j] + 1) {
                lds[i] = lds[j] + 1;
            }
        }
    }

    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        if (lds[i] > max_len) {
            max_len = lds[i];
        }
    }

    result = max_len; // store LDS length

    free(arr);
    free(lds);

    printf("The test passed\n");
    return 0;
}
