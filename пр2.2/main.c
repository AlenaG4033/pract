#include <stdio.h>
#include <stdlib.h>

void add(float a, float b) {
    system("chcp 65001");
    printf("add: %f + %f = %f\n", a, b, a + b);
}

void subtract(float a, float b) {
    printf("subtract: %f - %f = %f\n", a, b, a - b);
}

void multiply(float a, float b) {
    printf("multiply: %f * %f = %f\n", a, b, a * b);
}

void divide(float a, float b) {
    if (b == 0) {
        printf("divide by zero\n");
        return;
    }
    printf("divide: %f / %f = %f\n", a, b, a / b);
}

int main() {
    void (*operations[4])(float, float) = { add, subtract, multiply, divide };
    int action;
    float a, b;

    while (1) {
        printf("Введите число (1-4): ");
        if (scanf("%d", &action) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        if (action < 1 || action > 4) {
            printf("Invalid operation.\n");
            continue;
        }

        printf("Введите первое число: ");
        if (scanf("%f", &a) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        printf("Введите второе число: ");
        if (scanf("%f", &b) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        operations[action - 1](a, b);  // Вызов функции по указателю
    }

    return 0;
}