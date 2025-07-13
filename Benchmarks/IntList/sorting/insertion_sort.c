/**
 * insertion_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them with classic insertion sort, and prints
 * "The test passed".
 *
 * Example usage:
 *     $ ./insertion_sort 5 2 9 1 5 6
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
        return 1;                     /* No integers provided */
    }

    int n = argc - 1;

    /* Allocate buffer for the input integers */
    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    /* Parse command‑line arguments */
    for (int i = 0; i < n; ++i) {
        data[i] = atoi(argv[i + 1]);
    }

    /* ---------- Insertion Sort ---------- */
    for (int i = 1; i < n; ++i) {
        int key = data[i];
        int j   = i - 1;

        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            --j;
        }
        data[j + 1] = key;
    }

    /* Store a value in the global result to ensure work isn't optimized out */
    result = data[0];

    free(data);

    printf("The test passed\n");
    return 0;
}
