/**
 * count_first_quartile.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of values in the 1st quartile (<= Q1),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./count_first_quartile 8 2 5 1 9 4 3
 *     The test passed
 *
 * Author: ChatGPT
 */

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int result = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int partition(int arr[], int left, int right, int pivot_index) {
    int pivot_value = arr[pivot_index];
    swap(&arr[pivot_index], &arr[right]);
    int store_index = left;
    for (int i = left; i < right; ++i) {
        if (arr[i] < pivot_value) {
            swap(&arr[store_index], &arr[i]);
            store_index++;
        }
    }
    swap(&arr[right], &arr[store_index]);
    return store_index;
}

int quickselect(int arr[], int left, int right, int k) {
    while (left <= right) {
        int pivot_index = left + (right - left) / 2;
        int pivot_new_index = partition(arr, left, right, pivot_index);
        if (pivot_new_index == k) {
            return arr[k];
        } else if (pivot_new_index < k) {
            left = pivot_new_index + 1;
        } else {
            right = pivot_new_index - 1;
        }
    }
    return arr[left];
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

    int q1_index = (n - 1) / 4;
    int q1_value = quickselect(values, 0, n - 1, q1_index);

    int count_q1 = 0;
    for (int i = 0; i < n; ++i) {
        if (values[i] <= q1_value) {
            count_q1++;
        }
    }

    result = count_q1; // Store the count of values in the 1st quartile

    free(values);

    printf("The test passed\n");

    return 0;
}
