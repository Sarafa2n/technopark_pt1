#include <stdio.h>
#include <stdlib.h>
#include "utils.h"


void input_data(Country *array, int size){
    int square,population,status;

    for(int i = 0; i < size; i++) {
        do {
            printf("Введите: площать страны, "
                   "численность населения ");
            status = scanf("%10d%10d", &square, &population);
            fflush(stdin);
        } while(status != 2 || square <= 0 || population <= 0);
        array[i].square = square;
        array[i].population = population;
        array[i].density = (float)population / (float)square;
    }
}

void output_data(Country *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%.4f %d %d\n", array[i].density, array[i].square, array[i].population);
    }
}

int sort_by_density(Country *array, int size){
    if(array == NULL) {
        printf("Передан пустой массив структур");
        return 0;
    }

    int part = partition(array, size);

    if(part > 0)
        sort_by_density(array, part);
    if(part + 1 < size)
        sort_by_density(array + part + 1, size - (part + 1) );

    return 1;
}

int partition (Country *array, int size){
    if( size <= 1)
        return 0;

    Country pivot = array[size - 1];
    int head = 0,
        tail = size - 2;

    while(head <= tail) {
        for(; array[head].density < pivot.density; ++head);
        for(; tail >= 0 && array[tail].density >= pivot.density; --tail);
        if(head < tail)
            swap(&array[head++], &array[tail--]);
    }

    swap(&array[head], &array[size - 1]);

    return head;
}

void swap(Country *first, Country *second){
    Country third = *first;
    *first = *second;
    *second = third;
}

int input_size(){
    int size,status;

    do {
        printf("Введите количество вводимых данных\n");
        status = scanf("%100d", &size);
        // перенаправляем на ввод, без этого вечный цикл
        fflush(stdin);
    } while(status != 1 || size <= 0);

    return size;
}

