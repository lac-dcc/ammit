/**
 * binary_search_17.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using bubble sort, then performs a binary search
 * for the value 17. The found index (or -1 if not found) is stored
 * in the global `result` variable. The program finally prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./binary_search_17 4 17 8 2 10
 *     The test passed
 *
 * Notes:
 *  - Only allowed libc functions used: printf, atoi, malloc, free.
 *  - Computed results are not printed; only the final message is printed.
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

static void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

static int binary_search(int *arr, int n, int target) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int count = argc - 1;
    int *arr = (int *) malloc((unsigned long)(count * sizeof(int)));
    if (!arr) {
        return 1; // Allocation failed
    }

    for (int i = 0; i < count; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    bubble_sort(arr, count);

    int target = 17;
    int found_index = binary_search(arr, count, target);

    result = found_index; // Store result

    free(arr);

    printf("The test passed\n");

    return 0;
}
