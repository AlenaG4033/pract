#include <stdio.h>
#include <stdlib.h>

// Прототип функции для нахождения среднего арифметического
int average(int arr[], int size);

int main() {
    system("chcp 65001");
    // Создаем массив с числами
    int array[] = {1, 2, 3, 4, 5}; // создается массив array из пяти целых чисел
    int size = sizeof(array) / sizeof(int); //размер array путем деления размера всего массива на размер одного элемента

    int (*func_ptr)(int[], int) = &average; //указатель на функцию func_ptr, который указывает на функцию average
    int avg = func_ptr(array, size); //функция average через указатель, передавая ей массив array и его размер и сред арифмет сохр в переменной avg
    printf("Среднее арифметическое: %d\n", avg);

   return 0;
}


int average(int arr[], int size) { //определ функцию average, которая приним массив и его размер в качеств аргументов, вычисл сумму элемент массива и возвращ средн арифмет
    int sum = 0;
    for (int i = 0; i < size; i++) {//цикл проходит по всем элементам массива arr (от arr[0] до arr[size-1]) и прибавляет каждый элемент к переменной sum
        sum += arr[i];
    }
    return sum / size;
}