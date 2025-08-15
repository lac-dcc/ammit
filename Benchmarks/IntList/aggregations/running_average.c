/**
 * running_average.c
 *
 * This program reads a list of integers from argc/argv,
 * computes their running average (average at each prefix),
 * sums these averages, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./running_average 10 20 30
 *     The test passed
 *
 * In this example:
 *     Prefix averages: (10)=10, (10+20)/2=15, (10+20+30)/3=20
 *     Sum of running averages = 10 + 15 + 20 = 45
 *
 */

int result = 0;

int printf(const char *restrict format, ...);
int atoi(const char *nptr);

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int sum = 0;
    int total_running_average = 0;

    for (int i = 1; i < argc; ++i) {
        sum += atoi(argv[i]);
        total_running_average += sum / i;
    }

    result = total_running_average; // Store to prevent optimization removal

    printf("The test passed\n");

    return 0;
}
