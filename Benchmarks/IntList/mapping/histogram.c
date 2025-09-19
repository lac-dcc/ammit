/**
 * histogram.c
 *
 * This program reads a list of integers from argc/argv,
 * builds a frequency histogram mapping each unique value to
 * the number of times it appears, stores an aggregated checksum
 * of the histogram in the global `result` variable, and prints
 * "The test passed".
 *
 * The histogram is computed but not printed.
 *
 * Example usage:
 *     $ ./histogram 2 3 2 5 3 2
 *     The test passed
 *
 * Notes:
 *  - Only allowed libc functions are used: printf, atoi, malloc, free.
 *  - The result variable prevents unused computation elimination.
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

struct Pair {
    int value;
    int count;
};

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    // Allocate space for worst case: each number is unique
    struct Pair *hist = (struct Pair *)malloc((argc - 1) * sizeof(struct Pair));
    if (!hist) {
        return 1; // Allocation failed
    }

    int hist_size = 0;

    for (int i = 1; i < argc; ++i) {
        int value = atoi(argv[i]);
        int found = 0;
        for (int j = 0; j < hist_size; ++j) {
            if (hist[j].value == value) {
                hist[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            hist[hist_size].value = value;
            hist[hist_size].count = 1;
            hist_size++;
        }
    }

    // Compute a checksum of the histogram (value*count summed up)
    int checksum = 0;
    for (int i = 0; i < hist_size; ++i) {
        checksum += hist[i].value * hist[i].count;
    }

    result = checksum; // Store the computation result

    free(hist);

    printf("The test passed\n");

    return 0;
}
