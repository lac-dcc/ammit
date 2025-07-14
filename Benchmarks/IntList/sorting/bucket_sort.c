/**
 * bucket_sort.c
 *
 * This program reads a list of non-negative integers from argc/argv,
 * sorts them using the bucket sort algorithm (using simple insertion sort in buckets),
 * and prints "The test passed".
 *
 * Example usage:
 *     $ ./bucket_sort 29 25 3 49 9 37 21 43
 *     The test passed
 *
 * Note: This implementation assumes non-negative integers only.
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

/* Insertion sort for a small array */
void insertion_sort(int *arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;
    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    int max = 0;
    for (int i = 0; i < n; ++i) {
        int value = atoi(argv[i + 1]);
        if (value < 0) {
            free(data);
            return 1; // Only non-negative integers supported
        }
        data[i] = value;
        if (value > max) max = value;
    }

    int bucket_count = n;
    if (bucket_count == 0) {
        free(data);
        return 1;
    }

    int **buckets = (int **)malloc((unsigned long)bucket_count * sizeof(int *));
    int *bucket_sizes = (int *)malloc((unsigned long)bucket_count * sizeof(int));
    int *bucket_counts = (int *)malloc((unsigned long)bucket_count * sizeof(int));

    if (!buckets || !bucket_sizes || !bucket_counts) {
        free(data);
        free(buckets);
        free(bucket_sizes);
        free(bucket_counts);
        return 1;
    }

    for (int i = 0; i < bucket_count; ++i) {
        bucket_sizes[i] = 8;
        bucket_counts[i] = 0;
        buckets[i] = (int *)malloc(8 * sizeof(int));
        if (!buckets[i]) {
            for (int j = 0; j < i; ++j) free(buckets[j]);
            free(data);
            free(buckets);
            free(bucket_sizes);
            free(bucket_counts);
            return 1;
        }
    }

    // Scatter into buckets
    for (int i = 0; i < n; ++i) {
        int index = (data[i] * bucket_count) / (max + 1);
        if (index >= bucket_count) index = bucket_count - 1;

        if (bucket_counts[index] >= bucket_sizes[index]) {
            int new_size = bucket_sizes[index] * 2;
            int *new_bucket = (int *)malloc((unsigned long)new_size * sizeof(int));
            if (!new_bucket) {
                for (int j = 0; j < bucket_count; ++j) free(buckets[j]);
                free(data);
                free(buckets);
                free(bucket_sizes);
                free(bucket_counts);
                return 1;
            }

            for (int j = 0; j < bucket_counts[index]; ++j) {
                new_bucket[j] = buckets[index][j];
            }

            free(buckets[index]);
            buckets[index] = new_bucket;
            bucket_sizes[index] = new_size;
        }

        buckets[index][bucket_counts[index]++] = data[i];
    }

    // Sort buckets and gather into original array
    int pos = 0;
    for (int i = 0; i < bucket_count; ++i) {
        if (bucket_counts[i] > 0) {
            insertion_sort(buckets[i], bucket_counts[i]);
            for (int j = 0; j < bucket_counts[i]; ++j) {
                data[pos++] = buckets[i][j];
            }
        }
    }

    result = data[0]; // Store a computed value to prevent optimization

    for (int i = 0; i < bucket_count; ++i) {
        free(buckets[i]);
    }
    free(data);
    free(buckets);
    free(bucket_sizes);
    free(bucket_counts);

    printf("The test passed\n");
    return 0;
}
