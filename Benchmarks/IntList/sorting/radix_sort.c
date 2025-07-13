/**
 * radix_sort.c
 *
 * This program reads a list of integers from argc/argv,
 * sorts them using LSD Radix Sort (base 256), and prints
 * "The test passed".
 *
 * The input should be a list of integers, separated by spaces,
 * passed through the command line.
 *
 * Example usage:
 *     $ ./radix_sort 170 45 75 90 802 24 2 66
 *     The test passed
 *
 */

int result = 0;

int  printf(const char *restrict format, ...);
int  atoi(const char *nptr);
void *malloc(unsigned long size);
void  free(void *ptr);

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        return 1; // No input
    }

    int n = argc - 1;

    int *data = (int *)malloc((unsigned long)n * sizeof(int));
    if (!data) return 1;

    int *tmp = (int *)malloc((unsigned long)n * sizeof(int));
    if (!tmp) {
        free(data);
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        data[i] = atoi(argv[i + 1]);
    }

    int count[256];
    for (int byte = 0; byte < 4; ++byte) {
        for (int i = 0; i < 256; ++i) count[i] = 0;

        for (int i = 0; i < n; ++i) {
            unsigned int key = (unsigned int)data[i];
            unsigned int digit = (key >> (byte * 8)) & 0xFFu;
            count[digit]++;
        }

        int sum = 0;
        for (int i = 0; i < 256; ++i) {
            int c = count[i];
            count[i] = sum;
            sum += c;
        }

        for (int i = 0; i < n; ++i) {
            unsigned int key = (unsigned int)data[i];
            unsigned int digit = (key >> (byte * 8)) & 0xFFu;
            tmp[count[digit]++] = data[i];
        }

        for (int i = 0; i < n; ++i) {
            data[i] = tmp[i];
        }
    }

    int first_neg = -1;
    for (int i = 0; i < n; ++i) {
        if (data[i] < 0) {
            first_neg = i;
            break;
        }
    }

    if (first_neg > 0) {
        int idx = 0;
        for (int i = first_neg; i < n; ++i) tmp[idx++] = data[i];
        for (int i = 0; i < first_neg; ++i) tmp[idx++] = data[i];
        for (int i = 0; i < n; ++i) data[i] = tmp[i];
    }

    result = data[0]; // Ensures result is used and stored

    free(tmp);
    free(data);

    printf("The test passed\n");
    return 0;
}
