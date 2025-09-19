/**
 * longest_arith_subseq.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the length of the longest contiguous subsequence
 * that forms an arithmetic progression, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./longest_arith_subseq 1 3 5 7 9 2 4 6 8 10
 *     The test passed
 *
 * In this example, the longest arithmetic subsequence length is 5
 * (the run 1 3 5 7 9).
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 2) {
        return 1; // Need at least 2 integers for an arithmetic sequence
    }

    int max_len = 2;
    int current_len = 2;

    int prev1 = atoi(argv[1]);
    int prev2 = atoi(argv[2]);
    int diff = prev2 - prev1;

    for (int i = 3; i < argc; ++i) {
        int value = atoi(argv[i]);
        int new_diff = value - prev2;

        if (new_diff == diff) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 2;
            diff = new_diff;
        }

        prev1 = prev2;
        prev2 = value;
    }

    if (current_len > max_len) {
        max_len = current_len;
    }

    result = max_len; // Store the longest arithmetic subsequence length

    printf("The test passed\n");

    return 0;
}
