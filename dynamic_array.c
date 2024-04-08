
#include "dynamic_array.h"
#include <stdlib.h>
#include <stdio.h>

struct DynamicArray {
    int* array;
    int capacity;
    int n_elements;
};

DynamicArray* dynamic_array_alloc(int start_size) {
    DynamicArray* myStruct = malloc(sizeof(DynamicArray));
    myStruct->capacity = start_size;
    myStruct->n_elements = 0;
    myStruct->array = malloc(start_size * sizeof(int));
    return myStruct;
}
 void resize_the_array (DynamicArray* dynamic_array) {

    if(dynamic_array->n_elements == dynamic_array->capacity)
    {
        dynamic_array->array = realloc(dynamic_array->array, sizeof(int) * (2 * dynamic_array->capacity));

        dynamic_array->capacity*=2;
    }
 }



void dynamic_array_append(DynamicArray* dynamic_array, int element) {
    


    resize_the_array(dynamic_array);

    dynamic_array->array[dynamic_array->n_elements] = element;
    dynamic_array->n_elements = dynamic_array->n_elements + 1;



}

void dynamic_array_free(DynamicArray* dynamic_array){

    free(dynamic_array->array);
    free(dynamic_array);

}
int dynamic_array_get_size(DynamicArray* dynamic_array){

    int num_of_elements = dynamic_array->n_elements;
    return num_of_elements;


}
int dynamic_array_get_at_index(DynamicArray* dynamic_array, int index) {
    int element = dynamic_array->array[index];
    return element;
}



void dynamic_array_insert_at(DynamicArray* dynamic_array, int element, int index)
{
    resize_the_array(dynamic_array);


    int i;

    for (i = dynamic_array->n_elements; i > index; i--)
    {
            dynamic_array->array[i] =  dynamic_array->array[i - 1];
    }
    dynamic_array->array[index] = element;

    dynamic_array->n_elements++;




}


void dynamic_array_remove_at_index(DynamicArray* dynamic_array, int index){

    int i;

    for (i = index; i < dynamic_array->n_elements-1 ; i++)
    {
            dynamic_array->array[i] =  dynamic_array->array[i + 1];
    }

    dynamic_array->n_elements--;



}


