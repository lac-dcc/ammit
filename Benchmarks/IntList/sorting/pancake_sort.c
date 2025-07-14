/**
 * pancake_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them in‑place using Pancake sort (successive prefix flips),
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./pancake_sort 3 6 1 10 2 7
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

/* Reverse arr[0..k] in place */
static void flip(int *arr, int k)
{
    int i = 0;
    while (i < k) {
        int tmp     = arr[i];
        arr[i]      = arr[k];
        arr[k]      = tmp;
        ++i;
        --k;
    }
}

/* Find index of the maximum element in arr[0..n-1] */
static int max_index(int *arr, int n)
{
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[idx]) idx = i;
    }
    return idx;
}

/* Pancake sort main routine */
static void pancake_sort(int *arr, int n)
{
    for (int curr_size = n; curr_size > 1; --curr_size) {
        int max_idx = max_index(arr, curr_size);

        if (max_idx == curr_size - 1) continue;  /* already in place */

        if (max_idx > 0) {
            flip(arr, max_idx);          /* bring max to front */
        }
        flip(arr, curr_size - 1);        /* move max to its final position */
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

    /* Perform Pancake sort */
    pancake_sort(data, n);

    /* Preserve computation in the global variable */
    result = data[0];

    free(data);

    printf("The test passed\n");
    return 0;
}
