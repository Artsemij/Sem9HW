#include <stdio.h>
#include <ctype.h>

void replaceLetters(FILE* input, FILE* output) {
    char c;
    while ((c = fgetc(input)) != EOF) {
        if (c == 'a') {
            fputc('b', output);
        } else if (c == 'A') {
            fputc('B', output);
        } else if (c == 'b') {
            fputc('a', output);
        } else if (c == 'B') {
            fputc('A', output);
        } else {
            fputc(c, output);
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    replaceLetters(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
