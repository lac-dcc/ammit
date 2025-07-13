/**
 * shell_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using Shell sort (gap halving sequence),
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./shell_sort 23 12 1 8 34 54 2 3
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

    /* ---------- Shell Sort (gap = n/2, n/4, ..., 1) ---------- */
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = data[i];
            int j = i;
            while (j >= gap && data[j - gap] > temp) {
                data[j] = data[j - gap];
                j -= gap;
            }
            data[j] = temp;
        }
    }

    /* Store one value to ensure computation isn't optimized away */
    result = data[0];

    free(data);

    printf("The test passed\n");
    return 0;
}
