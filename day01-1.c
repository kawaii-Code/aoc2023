#include <stdio.h>

int is_digit(char c) {
    return '0' <= c && c <= '9';
}

int main(void) {
    int c, sum;
    int firstDigit, lastDigit;
    FILE *file;

    file = fopen("1.txt", "r");
    sum = 0;
    firstDigit = -1;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            if (firstDigit != -1) {
                sum += 10 * firstDigit + lastDigit;
                firstDigit = -1;
            }
        }

        if (is_digit(c)) {
            if (firstDigit == -1) {
                firstDigit = c - '0';
            }
            lastDigit = c - '0';
        }
    }

    printf("%d", sum);
}
