#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <pattern> <file>\n", argv[0]);
        return 1;
    }

    regex_t regex;
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    int line_num = 1;

    if (regcomp(&regex, argv[1], REG_EXTENDED)) {
        printf("Invalid regex pattern\n");
        return 1;
    }

    file = fopen(argv[2], "r");
    if (!file) {
        printf("Cannot open file: %s\n", argv[2]);
        regfree(&regex);
        return 1;
    }

    while (getline(&line, &len, file) != -1) {
        if (regexec(&regex, line, 0, NULL, 0) == 0) {
            printf("%d:%s", line_num, line);
        }
        line_num++;
    }

    free(line);
    fclose(file);
    regfree(&regex);
    return 0;
}