
typedef struct DynamicArray DynamicArray;


/**
 * Makes a DynamicArray.
 * @param start_size initial capacity to start array with
*/
DynamicArray* dynamic_array_alloc(int start_size);

void dynamic_array_append(DynamicArray* dynamic_array, int element);

void dynamic_array_insert_at(DynamicArray* dynamic_array, int element, int index);

int dynamic_array_get_size(DynamicArray* dynamic_array);

int dynamic_array_get_at_index(DynamicArray* dynamic_array, int index);

void dynamic_array_remove_at_index(DynamicArray* dynamic_array, int index);

void dynamic_array_free(DynamicArray* dynamic_array);