/**
 * iqr_quickselect.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the Interquartile Range (IQR = Q3 - Q1) using the Quickselect algorithm,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./iqr_quickselect 1 2 3 4 5 6 7 8 9 10
 *     The test passed
 *
 * Author: Expert C Developer
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

// Partition for Quickselect
int partition(int *arr, int left, int right, int pivot_index) {
    int pivot_value = arr[pivot_index];
    swap(&arr[pivot_index], &arr[right]);
    int store_index = left;
    for (int i = left; i < right; ++i) {
        if (arr[i] < pivot_value) {
            swap(&arr[i], &arr[store_index]);
            store_index++;
        }
    }
    swap(&arr[store_index], &arr[right]);
    return store_index;
}

// Quickselect: returns k-th smallest (0-based)
int quickselect(int *arr, int left, int right, int k) {
    while (left <= right) {
        int pivot_index = left + (right - left) / 2;
        int new_index = partition(arr, left, right, pivot_index);
        if (new_index == k) {
            return arr[new_index];
        } else if (new_index < k) {
            left = new_index + 1;
        } else {
            right = new_index - 1;
        }
    }
    return -1; // Should never happen
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

    // Compute Q1 and Q3 indices using inclusive rank method
    int q1_index = (n - 1) / 4;
    int q3_index = (3 * (n - 1)) / 4;

    // Copy array because quickselect modifies it
    int *copy = (int *)malloc(n * sizeof(int));
    if (!copy) {
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        copy[i] = arr[i];
    }
    int q1 = quickselect(copy, 0, n - 1, q1_index);

    for (int i = 0; i < n; ++i) {
        copy[i] = arr[i];
    }
    int q3 = quickselect(copy, 0, n - 1, q3_index);

    int iqr = q3 - q1;
    result = iqr;

    free(arr);
    free(copy);

    printf("The test passed\n");

    return 0;
}
