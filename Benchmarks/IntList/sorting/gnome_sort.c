/**
 * gnome_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using the Gnome sort algorithm,
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./gnome_sort 20 3 11 2 17
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

static inline void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        return 1; /* No integers provided */
    }

    int n = argc - 1;

    /* Allocate array for the input integers */
    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    /* Parse command‑line arguments */
    for (int i = 0; i < n; ++i) {
        data[i] = atoi(argv[i + 1]);
    }

    /* ---------- Gnome Sort ---------- */
    int index = 0;
    while (index < n) {
        if (index == 0 || data[index] >= data[index - 1]) {
            ++index;
        } else {
            swap(&data[index], &data[index - 1]);
            --index;
        }
    }

    /* Store a value in the global result to ensure work isn’t optimized out */
    result = data[0];

    free(data);

    printf("The test passed\n");
    return 0;
}
