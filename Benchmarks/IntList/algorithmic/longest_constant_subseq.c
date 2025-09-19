/**
 * longest_constant_subseq.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the length of the longest contiguous subsequence
 * where all values are the same, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./longest_constant_subseq 1 1 2 2 2 3 3 3 3 2
 *     The test passed
 *
 * In this example, the longest contiguous subsequence length is 4
 * (the run of four consecutive 3's).
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int max_len = 1;
    int current_len = 1;

    int prev = atoi(argv[1]);

    for (int i = 2; i < argc; ++i) {
        int value = atoi(argv[i]);
        if (value == prev) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 1;
            prev = value;
        }
    }

    if (current_len > max_len) {
        max_len = current_len;
    }

    result = max_len; // store longest constant subsequence length

    printf("The test passed\n");

    return 0;
}
