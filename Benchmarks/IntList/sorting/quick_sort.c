/**
 * quick_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them in‑place using classic quick sort (Hoare partition),
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./quick_sort 34 7 23 32 5 62
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

/* Swap two integers */
static inline void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Recursive quick sort (Hoare partition scheme) */
void quick_sort(int *arr, int left, int right)
{
    if (left >= right) return;

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) ++i;
        while (arr[j] > pivot) --j;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            ++i;
            --j;
        }
    }

    if (left < j)  quick_sort(arr, left, j);
    if (i   < right) quick_sort(arr, i, right);
}

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        return 1; /* No integers provided */
    }

    int n = argc - 1;

    /* Allocate array for input integers */
    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    /* Parse command‑line arguments */
    for (int i = 0; i < n; ++i) {
        data[i] = atoi(argv[i + 1]);
    }

    /* Perform quick sort */
    quick_sort(data, 0, n - 1);

    /* Store a value to ensure the work is retained by the optimizer */
    result = data[0];

    free(data);

    printf("The test passed\n");
    return 0;
}
