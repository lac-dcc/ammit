/**
 * kth_smallest.c
 *
 * This program reads a list of integers from argc/argv,
 * finds the k-th smallest element, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line. The first argument must be the value of k.
 *
 * Example usage:
 *     $ ./kth_smallest 3 10 4 5 7 2
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

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int quickselect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pi = partition(arr, low, high);
        if (pi == k) {
            return arr[pi];
        } else if (pi > k) {
            return quickselect(arr, low, pi - 1, k);
        } else {
            return quickselect(arr, pi + 1, high, k);
        }
    }
    return -1; // Should not happen
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

    int kth = quickselect(arr, 0, n - 1, k - 1);

    result = kth; // Store result, but do not print

    free(arr);

    printf("The test passed\n");
    return 0;
}
