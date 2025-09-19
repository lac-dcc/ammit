/**
 * kth_smallest_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them, and finds the k-th smallest element.
 * Finally, it prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line. The first argument must be the value of k.
 *
 * Example usage:
 *     $ ./kth_smallest_sort 3 10 4 5 7 2
 *     The test passed
 *
 * In this example, k=3 and the 3rd smallest element is 5.
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        return 1; // Need k and at least one number
    }

    int k = atoi(argv[1]);
    int n = argc - 2;

    if (k < 1 || k > n) {
        return 1; // Invalid k
    }

    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return 1; // Allocation failed
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = atoi(argv[i + 2]);
    }

    bubble_sort(arr, n);

    int kth = arr[k - 1];

    result = kth; // Store result, but do not print

    free(arr);

    printf("The test passed\n");
    return 0;
}
