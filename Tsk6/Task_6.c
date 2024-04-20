#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    char input[1000];
    fgets(input, sizeof(input), file);
    fclose(file);

    int count = 0;
    char* token = strtok(input, " ");
    while (token != NULL) {
        int length = strlen(token);
        if (tolower(token[length - 1]) == 'a') {
            count++;
        }
        token = strtok(NULL, " ");
    }

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    fprintf(file, "%d", count);
    fclose(file);

    return 0;
}