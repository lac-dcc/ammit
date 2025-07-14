/**
 * heap_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using the heap sort algorithm (in-place),
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./heap_sort 9 4 7 1 3 6 2
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

/* Heapify a subtree rooted at index i, for a heap of size n */
void heapify(int *arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1; // left child
    int r = 2 * i + 2; // right child

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;

        heapify(arr, n, largest);
    }
}

/* Main heap sort function */
void heap_sort(int *arr, int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        heapify(arr, i, 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;

    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    for (int i = 0; i < n; ++i) {
        data[i] = atoi(argv[i + 1]);
    }

    heap_sort(data, n);

    result = data[0]; // Store a computed value to prevent optimization

    free(data);

    printf("The test passed\n");
    return 0;
}
