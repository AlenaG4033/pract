#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 1000
#define NUM_THREADS 4

int array[ARRAY_SIZE];
int uniqueNumbers[ARRAY_SIZE];
int numUniqueNumbers = 0;
float average = 0;
pthread_mutex_t lock;

void* computeAverage(void* arg) {
    int start = (int)arg;
    int end = start + ARRAY_SIZE/NUM_THREADS;

    float sum = 0;
    for (int i = start; i < end; i++) {
        sum += array[i];
    }

    pthread_mutex_lock(&lock);
    average += sum;
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

void* findUniqueNumbers(void* arg) {
    int start = (int)arg;
    int end = start + ARRAY_SIZE/NUM_THREADS;

    for (int i = start; i < end; i++) {
        int isUnique = 1;
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (array[j] == array[i] && j != i) {
                isUnique = 0;
                break;
            }
        }
        if (isUnique) {
            pthread_mutex_lock(&lock);
            uniqueNumbers[numUniqueNumbers++] = array[i];
            pthread_mutex_unlock(&lock);
        }
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&lock, NULL);

    // Заполнение массива случайными числами
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10 + 1;
    }

    // Вычисление среднего арифметического в нескольких потоках
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, computeAverage, (void*)(i * ARRAY_SIZE / NUM_THREADS));
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    average /= ARRAY_SIZE;

    printf("Average: %f\n", average);

    // Поиск уникальных чисел в нескольких потоках
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, findUniqueNumbers, (void*)(i * ARRAY_SIZE / NUM_THREADS));
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Замена всех уникальных чисел на 0
    for (int i = 0; i < numUniqueNumbers; i++) {
        for (int j = 0; j < ARRAY_SIZE; j++) {
            if (array[j] == uniqueNumbers[i]) {
                array[j] = 0;
            }
        }
    }
    system("chcp 65001");
    printf("Уникальные числа заменены на 0:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    pthread_mutex_destroy(&lock);
    return 0;
}
