#include <stdlib.h>
#include <stdio.h>
#include "lib/utils.h"

int main() {
    int size = input_size();
    Country *array = malloc(size * sizeof(Country ));

    input_data(array, size);
    int status = sort_by_density(array, size);
    if (status)
        output_data(array, size);
    else
        printf("Ошибка передачи данных в функцию");
    free(array);
    return 0;
}