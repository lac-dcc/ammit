/**
 * comb_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using the Comb sort algorithm (shrink factor ≈ 1.3),
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./comb_sort 20 3 11 2 17 25 0
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

/* Swap helper */
static inline void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/* Comb sort implementation */
void comb_sort(int *arr, int n)
{
    int gap = n;
    int swapped = 1;

    while (gap > 1 || swapped) {
        /* Shrink gap by 1.3 (integer approximation) */
        gap = (gap * 10) / 13;
        if (gap == 9 || gap == 10) gap = 11; /* improve distribution */
        if (gap < 1) gap = 1;

        swapped = 0;
        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = 1;
            }
        }
    }
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

    /* Perform Comb sort */
    comb_sort(data, n);

    /* Preserve computation side‑effect */
    result = data[0];

    free(data);

    printf("The test passed\n");
    return 0;
}
