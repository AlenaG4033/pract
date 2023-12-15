#include <stdio.h>

// Объявление функции отдельно от ее инициализации
int isUnique(int arr[], int size, int num);

// Функция для замены уникальных чисел на 0
void replaceUnique(int arr[], int rows, int cols)
{
    int i, j;
    int (*isUniquePtr)(int[], int, int) = &isUnique; //создается указатель на функцию isUnique, который указывает на функцию isUnique
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if ((*isUniquePtr)(arr, rows * cols, arr[i * cols + j])) {
                arr[i * cols + j] = 0;
            }
        }
    }
}

// Функция для проверки, является ли число уникальным
int isUnique(int arr[], int size, int num)
{
    int i;
    int count = 0;
    for (i = 0; i < size; i++) {
        if (arr[i] == num) {
            count++;
            if (count > 1) {
                return 0;
            }
        }
    }

    return 1;
}

// Функции для калькулятора
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int main()
{
    int arr[3][3] = { {2, 1, 3}, {4, 3, 5}, {6, 7, 6} };
    int rows = 3;
    int cols = 3;
    int i, j;
    void (*replaceUniquePtr)(int[], int, int) = &replaceUnique; // Указатель на функцию replaceUnique

// Использование указателя на функцию для замены уникальных чисел на 0
    (*replaceUniquePtr)((int *)arr, rows, cols);

// Вывод результирующего массива
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

// Использование указателей на функции в калькуляторе
    system("chcp 65001");
    int a = 10, b = 5;
    int (*calculatorPtr[4])(int, int) = { &add, &subtract, &multiply, &divide };

    printf("Сложение: %d\n", (*calculatorPtr[0])(a, b));
    printf("Вычитание: %d\n", (*calculatorPtr[1])(a, b));
    printf("Умножение: %d\n", (*calculatorPtr[2])(a, b));
    printf("Деление: %d\n", (*calculatorPtr[3])(a, b));

    return 0;
}