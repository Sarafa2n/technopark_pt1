#ifndef DZ1_UTILS_H
#define DZ1_UTILS_H

typedef struct Country {
    int square;
    int population;
    float density;
}Country;


void input_data(Country *array, int size);
void output_data(Country *array, int size);
int sort_by_density(Country *array, int size);
void swap(Country *first, Country *second);
int partition (Country *array, int size);
int input_size();

#endif //DZ1_UTILS_H
