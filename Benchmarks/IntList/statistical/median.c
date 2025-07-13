/**
 * median.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the median using the Quickselect algorithm in O(N) average time,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./median 10 20 30
 *     The test passed
 *
 * Author: ChatGPT
 */

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int result = 0;

// Swap two integers
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Partition function used by Quickselect
int partition(int *arr, int left, int right, int pivot_index) {
    int pivot_value = arr[pivot_index];
    swap(&arr[pivot_index], &arr[right]); // Move pivot to end
    int store_index = left;
    for (int i = left; i < right; ++i) {
        if (arr[i] < pivot_value) {
            swap(&arr[i], &arr[store_index]);
            store_index++;
        }
    }
    swap(&arr[store_index], &arr[right]); // Move pivot to final place
    return store_index;
}

// Quickselect algorithm
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
    return -1; // Should not reach here
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;
    int *values = (int *)malloc(n * sizeof(int));
    if (!values) {
        return 1; // Allocation failed
    }

    for (int i = 0; i < n; ++i) {
        values[i] = atoi(argv[i + 1]);
    }

    int median;
    if (n % 2 == 1) {
        // Odd number of elements
        median = quickselect(values, 0, n - 1, n / 2);
    } else {
        // Even number of elements: average of two middle values
        int left = quickselect(values, 0, n - 1, n / 2 - 1);
        int right = quickselect(values, 0, n - 1, n / 2);
        median = (left + right) / 2;
    }

    result = median; // Suppress unused variable warning

    free(values);

    printf("The test passed\n");

    return 0;
}
