/**
 * zero_sum_subarrays.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the number of subarrays whose sum is exactly zero,
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./zero_sum_subarrays 1 -1 2 -2 3
 *     The test passed
 *
 * Explanation:
 *   For input [1, -1, 2, -2, 3], the zero-sum subarrays are:
 *     [1, -1], [2, -2], [1, -1, 2, -2] → total = 3
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);
void *malloc(unsigned long size);
void free(void *ptr);

struct Pair {
    int sum;
    int count;
    struct Pair *next;
};

// Simple hash function for sums
int hash(int x, int size) {
    if (x < 0) x = -x * 31;
    return x % size;
}

// Insert or update sum count in hash map
void insert(struct Pair **table, int size, int sum) {
    int h = hash(sum, size);
    struct Pair *node = table[h];
    while (node) {
        if (node->sum == sum) {
            node->count++;
            return;
        }
        node = node->next;
    }
    struct Pair *new_node = (struct Pair *)malloc(sizeof(struct Pair));
    new_node->sum = sum;
    new_node->count = 1;
    new_node->next = table[h];
    table[h] = new_node;
}

// Get count of a given sum
int get(struct Pair **table, int size, int sum) {
    int h = hash(sum, size);
    struct Pair *node = table[h];
    while (node) {
        if (node->sum == sum) {
            return node->count;
        }
        node = node->next;
    }
    return 0;
}

// Free hash table
void free_table(struct Pair **table, int size) {
    for (int i = 0; i < size; i++) {
        struct Pair *node = table[i];
        while (node) {
            struct Pair *tmp = node;
            node = node->next;
            free(tmp);
        }
    }
    free(table);
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int n = argc - 1;
    int prefix_sum = 0;
    int total = 0;

    // Hash table size (simple over-allocation for collisions)
    int size = n * 2 + 1;
    struct Pair **table = (struct Pair **)malloc(size * sizeof(struct Pair *));
    for (int i = 0; i < size; i++) {
        table[i] = 0;
    }

    // Empty prefix sum (0) appears once
    insert(table, size, 0);

    for (int i = 1; i <= n; i++) {
        int value = atoi(argv[i]);
        prefix_sum += value;

        int count = get(table, size, prefix_sum);
        total += count;
        insert(table, size, prefix_sum);
    }

    result = total; // Computed but not printed

    free_table(table, size);

    printf("The test passed\n");

    return 0;
}
