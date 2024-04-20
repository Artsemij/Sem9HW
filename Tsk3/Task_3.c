
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Функция для сравнения элементов массива, используется в qsort
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    char input[1000];
    fscanf(file, "%d[^\n]", input);
    fclose(file);

    int numbers[1000];
    int count = 0;

    // Извлечение чисел из строки и запись в массив
    char* token = strtok(input, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            numbers[count++] = atoi(token);
        }
        token = strtok(NULL, " ");
    }

    // Сортировка массива
    qsort(numbers, count, sizeof(int), compare);

    // Запись отсортированного массива в файл
    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d ", numbers[i]);
    }
    fclose(file);

    return 0;
}