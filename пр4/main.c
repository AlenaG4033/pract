#include <stdio.h>
#include <stdlib.h>
// Определение структуры AnotherStruct
typedef struct AnotherStruct {
    int some_var;
} AnotherStruct;
// Определение структуры Warrior, представляющей воина
typedef struct {
    int static_var;
    int* dynamic_var;
    int static_array[5];
    int* dynamic_array;
    void (*function_pointer)();
    AnotherStruct* another_struct;
} Warrior;
// Функция атаки воина
void attack() {
    system("chcp 65001");
    printf("Воин атакует!\n");
}
// Главная функция программы
int main() {
    system("chcp 65001");
    Warrior warrior;// Создание экземпляра структуры Warrior

    warrior.static_var = 10;// Присвоение значения статической переменной

    warrior.dynamic_var = (int*)malloc(sizeof(int));// Выделение памяти для динамической переменной
    *warrior.dynamic_var = 20;// Присвоение значения динамической переменной
    // Заполнение статического массива
    warrior.static_array[0] = 1;
    warrior.static_array[1] = 2;
    warrior.static_array[2] = 3;
    warrior.static_array[3] = 4;
    warrior.static_array[4] = 5;

    warrior.dynamic_array = (int*)malloc(3 * sizeof(int));// Выделение памяти для динамического массива
    warrior.dynamic_array[0] = 6;// Присвоение значения элементу динамического массива
    warrior.dynamic_array[1] = 7;
    warrior.dynamic_array[2] = 8;

    warrior.function_pointer = attack;// Присвоение указателя на функцию атаки воина функциональному указателю

    warrior.another_struct = (AnotherStruct*)malloc(sizeof(AnotherStruct));// Выделение памяти для экземпляра AnotherStruct
    warrior.another_struct->some_var = 30;// Присвоение значения полю some_var в экземпляре AnotherStruct
    // Вывод значений переменных и массивов
    printf("Статическая переменная: %d\n", warrior.static_var);
    printf("Динамическая переменная: %d\n", *warrior.dynamic_var);

    printf("Статический массив: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", warrior.static_array[i]);
    }
    printf("\n");

    printf("Динамический массив: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", warrior.dynamic_array[i]);
    }
    printf("\n");

    warrior.function_pointer();// Вызов функции атаки через функциональный указатель

    printf("Переменная в другой структуре: %d\n", warrior.another_struct->some_var);
    // Освобождение динамически выделенной памят
    free(warrior.dynamic_var);
    free(warrior.dynamic_array);
    free(warrior.another_struct);

    return 0;
}