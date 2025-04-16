#include <stdio.h>

/*
    Demonstrates:
    1. Storing a value in a variable.
    2. Printing its memory address.
    3. Using a pointer to read/write the value.
*/

int main(void) 
{
    // Step 1: Initialize a variable
    char initial_value = 100;
    printf("Initial value: %d\n", initial_value);
    printf("Memory address: %p\n", (void*)&initial_value);

    // Step 2: Create a pointer to the variable
    char* value_pointer = &initial_value;

    // Step 3: Read the value through the pointer
    char read_value = *value_pointer;
    printf("Value read via pointer: %d\n", read_value);

    // Step 4: Modify the value through the pointer
    *value_pointer = 65;
    printf("Updated value: %d\n", initial_value);

    return 0;
}