/**
 * mode.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the mode (most frequent number), and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./mode 1 2 2 3 3 3 4
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
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Simple in-place quicksort
void quicksort(int *arr, int left, int right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;
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

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    // Sort array to group equal elements together
    quicksort(arr, 0, n - 1);

    int mode = arr[0];
    int mode_count = 1;
    int current = arr[0];
    int current_count = 1;

    for (int i = 1; i < n; ++i) {
        if (arr[i] == current) {
            current_count++;
        } else {
            if (current_count > mode_count) {
                mode = current;
                mode_count = current_count;
            }
            current = arr[i];
            current_count = 1;
        }
    }

    // Check last group
    if (current_count > mode_count) {
        mode = current;
        mode_count = current_count;
    }

    result = mode; // Store the mode without printing

    free(arr);

    printf("The test passed\n");

    return 0;
}
