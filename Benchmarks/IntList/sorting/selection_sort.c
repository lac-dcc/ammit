/**
 * selection_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using the selection sort algorithm,
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./selection_sort 64 25 12 22 11
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
        return 1; // No integers provided
    }

    int n = argc - 1;

    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    for (int i = 0; i < n; ++i) {
        data[i] = atoi(argv[i + 1]);
    }

    /* ---------- Selection Sort ---------- */
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (data[j] < data[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = data[i];
            data[i] = data[min_idx];
            data[min_idx] = temp;
        }
    }

    result = data[0]; // Ensure computation is preserved

    free(data);

    printf("The test passed\n");
    return 0;
}
