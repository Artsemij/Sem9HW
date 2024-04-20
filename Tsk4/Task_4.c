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

char result[1000];
int resultIndex = 0;

for (int i = 0; i < strlen(input); i++) {
if (!isspace(input[i])) {
int j;
for (j = 0; j < resultIndex; j++) {
if (tolower(input[i]) == tolower(result[j])) {
break;
}
}
if (j == resultIndex) {
result[resultIndex++] = input[i];
}
}
}
result[resultIndex] = '\0';

file = fopen("output.txt", "w");
if (file == NULL) {
printf("Ошибка открытия файла\n");
return 1;
}
fprintf(file, "%s", result);
fclose(file);

return 0;
}