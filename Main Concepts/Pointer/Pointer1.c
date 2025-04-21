#include <stdio.h>

// Global variable 
long long int global_data = 0xFFFEABCD11112345;  

int main(void) 
{
  
    char *byte_ptr = (char*)&global_data;
    printf("Value at address %p (byte): 0x%x\n", byte_ptr, *byte_ptr);

    
    int *int_ptr = (int*)&global_data;
    printf("Value at address %p (int):   0x%x\n", int_ptr, *int_ptr);

    
    short *short_ptr = (short*)&global_data;
    printf("Value at address %p (short): 0x%x\n", short_ptr, *short_ptr);


    long long *ll_ptr = (long long*)&global_data;
    printf("Value at address %p (long long): 0x%llx\n", ll_ptr, *ll_ptr);

    return 0;
}