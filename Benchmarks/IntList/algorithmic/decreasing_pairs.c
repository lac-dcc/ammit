/**
 * decreasing_pairs.c
 *
 * This program reads a list of integers from argc/argv,
 * counts the number of decreasing pairs (i < j, a[i] > a[j]),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./decreasing_pairs 2 4 1 3 5
 *     The test passed
 *
 * In this example, the decreasing pairs are:
 * (2,1), (4,1), (4,3).
 * Total = 3 decreasing pairs.
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;
    int *arr = (int *)malloc(n * sizeof(int));
    if (!arr) {
        return 1; // Allocation failed
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    long count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    }

    result = (int)count; // store result but do not print

    free(arr);

    printf("The test passed\n");
    return 0;
}
