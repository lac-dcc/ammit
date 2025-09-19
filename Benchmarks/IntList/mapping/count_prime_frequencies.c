/**
 * count_prime_frequencies.c
 *
 * This program reads a list of integers from argc/argv,
 * counts how many unique values appear with frequency equal to a prime number,
 * stores the result in the global `result` variable, and
 * prints "The test passed".
 *
 * The computation is performed but not printed.
 *
 * Example usage:
 *     $ ./count_prime_frequencies 2 3 2 5 3 2 7 7 7 8
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

int is_prime(int n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

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

    // Count values whose frequency is prime
    int prime_freq_count = 0;
    for (int i = 0; i < hist_size; ++i) {
        if (is_prime(hist[i].count)) {
            prime_freq_count++;
        }
    }

    result = prime_freq_count; // Store the computation result

    free(hist);

    printf("The test passed\n");

    return 0;
}
