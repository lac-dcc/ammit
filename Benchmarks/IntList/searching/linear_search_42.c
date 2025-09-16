/**
 * linear_search_42.c
 *
 * This program reads a list of integers from argc/argv,
 * performs a linear search for the value 42, stores the found
 * index (or -1 if not found) in the global `result` variable,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./linear_search_42 10 42 5 7
 *     The test passed
 *
 * Notes:
 *  - The program depends only on libc.
 *  - Allowed libc functions used: printf, atoi, malloc, free.
 *  - All computed results are NOT printed; only the final message is printed.
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

    int count = argc - 1;
    /* allocate space for integers parsed from argv */
    int *arr = (int *) malloc((unsigned long) (count * sizeof(int)));
    if (!arr) {
        return 1; // allocation failed
    }

    /* parse inputs into array */
    for (int i = 0; i < count; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    /* linear search for value 42 */
    int target = 42;
    int found_index = -1;
    for (int i = 0; i < count; ++i) {
        if (arr[i] == target) {
            found_index = i; /* store first occurrence */
            break;
        }
    }

    /* store computed result to prevent optimization away */
    result = found_index;

    free(arr);

    printf("The test passed\n");

    return 0;
}
