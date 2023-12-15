#include <stdio.h>

int main() {
    system("chcp 65001");
    // Открытие текстового файла для чтения
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Ошибка при открытии файла input.txt");
        return 1;
    }

    // Открытие текстового файла для записи
    FILE *outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Ошибка при открытии файла output.txt");
        fclose(inputFile);
        return 1;
    }

    // Чтение чисел из файла и вычисление среднего арифметического
    int count = 0;
    int sum = 0;
    int num;

    while (fscanf(inputFile, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count == 0) {
        printf("Файл input.txt не содержит чисел");
        fclose(inputFile);
        fclose(outputFile);
        return 1;
    }

    float average = (float) sum / count;

    // Запись среднего арифметического в файл
    fprintf(outputFile, "%.2f", average);

    // Закрытие файлов
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
