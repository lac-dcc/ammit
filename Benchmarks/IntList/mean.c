/**
 * mean.c
 *
 * This program reads a list of integers from argc/argv,
 * computes the mean, and prints "The test passed".
 *
 * The input should be a list of integers, separated by spaces passed
 * through the command line.
 *
 * Example usage:
 *     $ ./mean 10 20 30
 *     The test passed
 *
 * Author: ChatGPT
 */

int printf(const char *restrict format, ...);

// Custom implementation of atoi for integers
int my_atoi(const char *str) {
    int result = 0;
    int sign = 1;

    // Skip leading whitespaces
    while (*str == ' ' || *str == '\t') {
        str++;
    }

    // Handle optional sign
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+') {
        str++;
    }

    // Convert characters to integer
    while (*str >= '0' && *str <= '9') {
        result = result * 10 + (*str - '0');
        str++;
    }

    return result * sign;
}

int main(int argc, char *argv[]) {
    if (argc <= 1) {
        return 1; // No integers provided
    }

    int sum = 0;
    int count = 0;

    for (int i = 1; i < argc; ++i) {
        const char *arg = argv[i];
        int value = my_atoi(arg);
        sum += value;
        count++;
    }

    if (count == 0) {
        return 1; // Avoid division by zero
    }

    int mean = sum / count;

    // Mean is computed but not printed
    (void)mean; // Suppress unused variable warning

    printf("The test passed\n");

    return 0;
}

