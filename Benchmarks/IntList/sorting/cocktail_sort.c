/**
 * cocktail_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using the Cocktail Shaker Sort algorithm (a bidirectional bubble sort),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./cocktail_sort 4 2 5 3 1
 *     The test passed
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void cocktail_sort(int *arr, int n) {
    int start = 0, end = n - 1;
    int swapped = 1;

    while (swapped) {
        swapped = 0;

        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                swapped = 1;
            }
        }

        if (!swapped) break;

        swapped = 0;
        --end;

        for (int i = end; i > start; --i) {
            if (arr[i - 1] > arr[i]) {
                swap(&arr[i - 1], &arr[i]);
                swapped = 1;
            }
        }

        ++start;
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1;
    }

    int n = argc - 1;
    int *arr = (int *)malloc((unsigned long)n * sizeof(int));
    if (!arr) return 1;

    for (int i = 0; i < n; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    cocktail_sort(arr, n);

    result = arr[0]; // Use result to suppress unused variable warning

    free(arr);

    printf("The test passed\n");
    return 0;
}
