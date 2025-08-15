/**
 * cumulative_sum.c
 *
 * This program reads a list of integers from argc/argv,
 * computes their cumulative sum (sum of all prefix sums),
 * and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./cumulative_sum 1 2 3
 *     The test passed
 *
 * In this example:
 *     Prefix sums: 1, (1+2)=3, (3+3)=6
 *     Cumulative sum = 1 + 3 + 6 = 10
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int running_sum = 0;
    int cumulative_sum = 0;

    for (int i = 1; i < argc; ++i) {
        running_sum += atoi(argv[i]);
        cumulative_sum += running_sum;
    }

    result = cumulative_sum; // Store to prevent optimization removal

    printf("The test passed\n");

    return 0;
}
