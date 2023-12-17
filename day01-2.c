#include <stdio.h>

int strfind(char str[], char q[], int start);
int first_digit(char line[], int linelen);
int last_digit(char line[], int linelen);
int searchdigit(char str[], char digitstr[], char digitalt[], int start);
int getline(char line[], int maxline);

int main(void) {
    int fd, ld, sum;
    char line[1024];
    int linelen;

    sum = 0;
    while (linelen = getline(line, 1024)) {
        fd = first_digit(line, linelen);
        ld = last_digit(line, linelen);
        if (fd != -1 && ld != -1) {
            sum += 10*fd + ld;
        }
    }
    printf("%d\n", sum);
}

int getline(char line[], int maxline) {
    int i, c;

    i = 0; 
    while (i < maxline && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}

int first_digit(char line[], int linelen) {
    int digit, min, i;

    digit = -1;
    min = linelen;
    if ((i = strfind(line, "one", 0)) != -1 && i < min) {
        digit = 1;
        min = i;
    }
    if ((i = strfind(line, "1", 0)) != -1 && i < min) {
        digit = 1;
        min = i;
    }
    if ((i = strfind(line, "two", 0)) != -1 && i < min) {
        digit = 2;
        min = i;
    }
    if ((i = strfind(line, "2", 0)) != -1 && i < min) {
        digit = 2;
        min = i;
    }
    if ((i = strfind(line, "three", 0)) != -1 && i < min) {
        digit = 3;
        min = i;
    }
    if ((i = strfind(line, "3", 0)) != -1 && i < min) {
        digit = 3;
        min = i;
    }
    if ((i = strfind(line, "four", 0)) != -1 && i < min) {
        digit = 4;
        min = i;
    }
    if ((i = strfind(line, "4", 0)) != -1 && i < min) {
        digit = 4;
        min = i;
    }
    if ((i = strfind(line, "five", 0)) != -1 && i < min) {
        digit = 5;
        min = i;
    }
    if ((i = strfind(line, "5", 0)) != -1 && i < min) {
        digit = 5;
        min = i;
    }
    if ((i = strfind(line, "six", 0)) != -1 && i < min) {
        digit = 6;
        min = i;
    }
    if ((i = strfind(line, "6", 0)) != -1 && i < min) {
        digit = 6;
        min = i;
    }
    if ((i = strfind(line, "seven", 0)) != -1 && i < min) {
        digit = 7;
        min = i;
    }
    if ((i = strfind(line, "7", 0)) != -1 && i < min) {
        digit = 7;
        min = i;
    }
    if ((i = strfind(line, "eight", 0)) != -1 && i < min) {
        digit = 8;
        min = i;
    }
    if ((i = strfind(line, "8", 0)) != -1 && i < min) {
        digit = 8;
        min = i;
    }
    if ((i = strfind(line, "nine", 0)) != -1 && i < min) {
        digit = 9;
        min = i;
    }
    if ((i = strfind(line, "9", 0)) != -1 && i < min) {
        digit = 9;
        min = i;
    }

    return digit;
}

int last_digit(char line[], int linelen) {
    int digit, max, i;

    digit = -1;
    max = -1;
    while ((i = strfind(line, "one", max + 1)) != -1) {
        digit = 1;
        max = i;
    }
    while ((i = strfind(line, "1", max + 1)) != -1) {
        digit = 1;
        max = i;
    }
    while ((i = strfind(line, "two", max + 1)) != -1) {
        digit = 2;
        max = i;
    }
    while ((i = strfind(line, "2", max + 1)) != -1) {
        digit = 2;
        max = i;
    }
    while ((i = strfind(line, "three", max + 1)) != -1) {
        digit = 3;
        max = i;
    }
    while ((i = strfind(line, "3", max + 1)) != -1) {
        digit = 3;
        max = i;
    }
    while ((i = strfind(line, "four", max + 1)) != -1) {
        digit = 4;
        max = i;
    }
    while ((i = strfind(line, "4", max + 1)) != -1) {
        digit = 4;
        max = i;
    }
    while ((i = strfind(line, "five", max + 1)) != -1) {
        digit = 5;
        max = i;
    }
    while ((i = strfind(line, "5", max + 1)) != -1) {
        digit = 5;
        max = i;
    }
    while ((i = strfind(line, "six", max + 1)) != -1) {
        digit = 6;
        max = i;
    }
    while ((i = strfind(line, "6", max + 1)) != -1) {
        digit = 6;
        max = i;
    }
    while ((i = strfind(line, "seven", max + 1)) != -1) {
        digit = 7;
        max = i;
    }
    while ((i = strfind(line, "7", max + 1)) != -1) {
        digit = 7;
        max = i;
    }
    while ((i = strfind(line, "eight", max + 1)) != -1) {
        digit = 8;
        max = i;
    }
    while ((i = strfind(line, "8", max + 1)) != -1) {
        digit = 8;
        max = i;
    }
    while ((i = strfind(line, "nine", max + 1)) != -1) {
        digit = 9;
        max = i;
    }
    while ((i = strfind(line, "9", max + 1)) != -1) {
        digit = 9;
        max = i;
    }

    return digit;
}

int searchdigit(char str[], char digitstr[], char digitalt[], int start) {
    int i;

    if ((i = strfind(str, digitstr, start)) != -1) {
        return i;
    }
    if ((i = strfind(str, digitalt, start)) != -1) {
        return i;
    }
}

int strfind(char str[], char q[], int start) {
    int i, j, k;

    for (i = start; str[i] != '\0'; i++) {
        for (j = i, k = 0; q[k] != '\0' && str[j] == q[k]; j++, k++)
            ;

        if (q[k] == '\0') {
            return i;
        }
    }

    return -1;
}
