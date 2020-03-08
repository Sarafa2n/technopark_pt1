#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "src/lib/utils.h"

void test_sort();
Country *test_data(int size);
int check_data(Country *array, int size);


int main (){
    test_sort();
    return 0;
}

void test_sort(){
    int size = 10;
    Country * array = test_data(size);

    {
        sort_by_density(array, size);
        int result = check_data(array, size);
        assert(result == 1);
    }
    {
        int status = sort_by_density(NULL, size);
        assert(status == 0);
    }

    free(array);
}

Country *test_data(int size){
    Country *array = malloc(size * sizeof(Country));

    for(int i = 0; i < size; i++){
        array[i].square = rand() + 1;
        array[i].population = rand() + 1;
        array[i].density = (float)array[i].population / (float)array[i].square ;
    }

    return array;
}

int check_data(Country *array, int size) {
    if (size > 1)
        for(int i = 0, j = 1; i < (size - 1); i++, j++) {
            if(array[i].density > array[j].density)
                return 0;
        }
    return 1;
}
