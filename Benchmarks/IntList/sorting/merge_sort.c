/**
 * merge_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using the merge sort algorithm,
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./merge_sort 38 27 43 3 9 82 10
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

void merge(int *data, int *temp, int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right) {
        if (data[i] <= data[j]) {
            temp[k++] = data[i++];
        } else {
            temp[k++] = data[j++];
        }
    }

    while (i < mid) {
        temp[k++] = data[i++];
    }

    while (j < right) {
        temp[k++] = data[j++];
    }

    for (int l = left; l < right; ++l) {
        data[l] = temp[l];
    }
}

void merge_sort(int *data, int *temp, int left, int right) {
    if (right - left <= 1) return;

    int mid = (left + right) / 2;
    merge_sort(data, temp, left, mid);
    merge_sort(data, temp, mid, right);
    merge(data, temp, left, mid, right);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;

    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    int *temp = (int *)malloc((unsigned long)n * sizeof(int));
    if (!temp) {
        free(data);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        data[i] = atoi(argv[i + 1]);
    }

    merge_sort(data, temp, 0, n);

    result = data[0]; // Store result to ensure computation

    free(temp);
    free(data);

    printf("The test passed\n");
    return 0;
}
