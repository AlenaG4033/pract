#include <stdio.h>

#define MAX_SIZE 100

int main() {
    system("chcp 65001");
    // Открытие файлов
    FILE *inputFile = fopen("input.txt", "r");
    FILE *outputFile = fopen("output.txt", "w");

    // Проверка, удалось ли открыть файлы
    if (inputFile == NULL || outputFile == NULL) {
        printf("Ошибка открытия файлов!\n");
        return 1;
    }

    // Объявление переменных
    int grid[MAX_SIZE][MAX_SIZE];
    int row, col, i, j, num, unique;

    // Чтение данных из input.txt и загрузка их в массив
    fscanf(inputFile, "%d %d", &row, &col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            fscanf(inputFile, "%d", &grid[i][j]);
        }
    }

    // Проверка строк на уникальные числа
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            num = grid[i][j];
            unique = 1;
            for (int k = 0; k < col; k++) {
                if (grid[i][k] == num && k != j) {
                    unique = 0;
                    break;
                }
            }
            if (unique) {
                for (int k = 0; k < row; k++) {
                    if (grid[k][j] == num && k != i) {
                        unique = 0;
                        break;
                    }
                }
            }
            if (unique) {
                grid[i][j] = 0;
            }
        }
    }

    // Запись обработанных данных в output.txt
    fprintf(outputFile, "%d %d\n", row, col);
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            fprintf(outputFile, "%d ", grid[i][j]);
        }
        fprintf(outputFile, "\n");
    }

    // Закрытие файлов
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}