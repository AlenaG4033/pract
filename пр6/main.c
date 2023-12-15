#include <stdio.h>

// Функция для нахождения среднего арифметического всех чисел в массиве
float findAverage(int arr[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    return (float)sum / n;
}

// Макрос без параметров для вывода приветственного сообщения
#define GREETING printf("Привет, мир!\n");

int main() {
    system("chcp 65001");
    // Исходный массив
    int arr[] = { 4, 6, 8, 2, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Вызываем макрос без параметров для вывода приветственного сообщения
    GREETING

    // Находим среднее арифметическое всех чисел в массиве
    float average = findAverage(arr, n);

    // Выводим результат
    printf("Среднее арифметическое: %.2f\n", average);

    return 0;
}
