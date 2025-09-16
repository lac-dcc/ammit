/**
 * array_palindrome.c
 *
 * This program reads a list of integers from argc/argv,
 * checks whether the sequence of integers forms a palindrome,
 * stores the result (1 if palindrome, 0 otherwise) in the global
 * `result` variable, and prints "The test passed".
 *
 * An array is considered a palindrome if the sequence reads the same
 * forwards and backwards.
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./array_palindrome 1 2 3 2 1
 *     The test passed
 *
 * Notes:
 *  - Only allowed libc functions used: printf, atoi.
 *  - The computed result is not printed; only the final message is printed.
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int left = 1;
    int right = argc - 1;
    int is_palindrome = 1;

    while (left < right) {
        int lval = atoi(argv[left]);
        int rval = atoi(argv[right]);
        if (lval != rval) {
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    // Store result (1 if palindrome, 0 otherwise)
    result = is_palindrome;

    printf("The test passed\n");

    return 0;
}
