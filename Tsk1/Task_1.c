#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Функция для подсчета вхождений каждой буквы в слове
void countLetters(char* word, int* counts) {
    for (int i = 0; i < strlen(word); i++) {
        counts[word[i] - 'a']++;
    }
}

// Функция для нахождения букв, которые встречаются один раз в обоих словах
char* findUniqueLetters(char* word1, char* word2) {
    int counts1[26] = {0};
    int counts2[26] = {0};
    countLetters(word1, counts1);
    countLetters(word2, counts2);

    char* uniqueLetters = (char*)malloc(26 * sizeof(char));
    int uniqueCount = 0;
    
    for (int i = 0; i < 26; i++) {
        if (counts1[i] == 1 && counts2[i] == 0) {
            uniqueLetters[uniqueCount++] = 'a' + i;
        }
        if (counts2[i] == 1 && counts1[i] == 0) {
            uniqueLetters[uniqueCount++] = 'a' + i;
        }
    }
    uniqueLetters[uniqueCount] = '\0';
    return uniqueLetters;
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    char word1[101], word2[101];
    fscanf(file, "%s %s", word1, word2);
    fclose(file);

    char* uniqueLetters = findUniqueLetters(word1, word2);

    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }
    fprintf(file, "%s", uniqueLetters);
    fclose(file);
    free(uniqueLetters);

    return 0;
}