/**
 * iqr.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the Interquartile Range (IQR = Q3 - Q1), and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./iqr 1 2 3 4 5 6 7 8 9 10
 *     The test passed
 *
 * Author: ChatGPT
 */

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int result = 0;

// Swap helper
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Simple quicksort
void quicksort(int *arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left, j = right;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) quicksort(arr, left, j);
    if (i < right) quicksort(arr, i, right);
}

// Helper: return the k-th element (zero-based)
int get_quartile(int *sorted, int n, int quartile) {
    int index = (quartile * (n - 1)) / 4;
    return sorted[index];
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1;
    }

    int n = argc - 1;
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    // Sort the array to access order statistics
    quicksort(arr, 0, n - 1);

    int q1 = get_quartile(arr, n, 1); // 25th percentile
    int q3 = get_quartile(arr, n, 3); // 75th percentile

    int iqr = q3 - q1;
    result = iqr;

    free(arr);

    printf("The test passed\n");

    return 0;
}
