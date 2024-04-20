#include <stdio.h>
#include <string.h>

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    char input[1000];
    fscanf(file, "%[^\n]", input);
    fclose(file);

    char* longestWord = "";
    int maxLength = 0;

    char* token = strtok(input, " ");
    while (token != NULL) {
        if (strlen(token) > maxLength) {
            longestWord = token;
            maxLength = strlen(token);
        }
        token = strtok(NULL, " ");
    }

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    fprintf(file, "%s", longestWord);
    fclose(file);

    return 0;
}