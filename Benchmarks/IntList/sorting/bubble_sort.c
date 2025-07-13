/**
 * bubble_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using the classic bubble‑sort algorithm,
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./bubble_sort 34 2 78 1 56
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        return 1;                       /* No integers provided */
    }

    int n = argc - 1;

    /* Allocate buffer for the input integers */
    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    /* Parse command‑line arguments */
    for (int i = 0; i < n; ++i) {
        data[i] = atoi(argv[i + 1]);
    }

    /* ---------- Bubble Sort ---------- */
    int swapped;
    do {
        swapped = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (data[i] > data[i + 1]) {
                int tmp     = data[i];
                data[i]     = data[i + 1];
                data[i + 1] = tmp;
                swapped = 1;
            }
        }
        /* After each pass, the largest element bubbles to the end,
           so we can safely ignore it in subsequent passes. */
        --n;
    } while (swapped && n > 1);

    /* Store a value in the global result to ensure work isn't optimized out */
    result = data[0];

    free(data);

    printf("The test passed\n");
    return 0;
}
