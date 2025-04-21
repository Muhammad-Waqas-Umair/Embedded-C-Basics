#include <stdio.h>

/*
    Demonstrates:
    1. Storing a value in a variable.
    2. Printing its memory address.
    3. Using a pointer to read/write the value.
*/

int main(void) 
{
    
    char initial_value = 100;
    printf("Initial value: %d\n", initial_value);
    printf("Memory address: %p\n", (void*)&initial_value);

    char* value_pointer = &initial_value;

    char read_value = *value_pointer;
    printf("Value read via pointer: %d\n", read_value);

    *value_pointer = 65;
    printf("Updated value: %d\n", initial_value);

    return 0;
}