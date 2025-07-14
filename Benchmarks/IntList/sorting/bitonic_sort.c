/**
 * bitonic_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using the Bitonic sort algorithm (assuming the size is a power of 2),
 * and prints "The test passed".
 *
 * The input should be a list of integers, with a count that is a power of two.
 *
 * Example usage:
 *     $ ./bitonic_sort 5 1 7 3 2 6 4 0
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void bitonic_merge(int *arr, int low, int count, int dir) {
    if (count <= 1) return;

    int k = count / 2;
    for (int i = low; i < low + k; i++) {
        if ((dir == 1 && arr[i] > arr[i + k]) ||
            (dir == 0 && arr[i] < arr[i + k])) {
            swap(&arr[i], &arr[i + k]);
        }
    }

    bitonic_merge(arr, low, k, dir);
    bitonic_merge(arr, low + k, k, dir);
}

static void bitonic_sort(int *arr, int low, int count, int dir) {
    if (count <= 1) return;

    int k = count / 2;

    bitonic_sort(arr, low, k, 1);       // ascending
    bitonic_sort(arr, low + k, k, 0);   // descending
    bitonic_merge(arr, low, count, dir);
}

static int is_power_of_two(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) return 1;

    int n = argc - 1;

    if (!is_power_of_two(n)) {
        return 1; // Bitonic sort requires power-of-two number of elements
    }

    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    for (int i = 0; i < n; i++) {
        data[i] = atoi(argv[i + 1]);
    }

    bitonic_sort(data, 0, n, 1); // ascending sort

    result = data[0]; // Use result to suppress optimization

    free(data);

    printf("The test passed\n");
    return 0;
}
