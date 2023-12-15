#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для нахождения среднего арифметического в одномерном массиве
float average(int n, int* arr) {
    float sum = 0.0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum / n;
}

// Функция для нахождения среднего арифметического в двумерном массиве
float average_2d(int rows, int cols, int** array) {
    int sum = 0;
    int total = rows * cols;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += array[i][j];
        }
    }

    return sum / (float)total;
}

// Функция для печати двумерного массива
void print_matrix(int rows, int cols, int array[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", array[i][j]);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    system("chcp 65001");
    int arr[5] = {0};
    int matrix[5][5] = {{0}};

    // Заполнение массивов случайными числами и их вывод
    for (int i = 0; i < 5; ++i) {
        arr[i] = rand() % 100;
        matrix[i / 5][i % 5] = arr[i];
    }

    printf("Одномерный массив:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nСреднее арифметическое в одномерном массиве: %f\n", average(5, arr));

    printf("\nДвумерный массив:\n");
    print_matrix(5, 5, matrix);
    printf("Среднее арифметическое в двумерном массиве: %f\n", average_2d(5, 5, matrix));

    return 0;
}