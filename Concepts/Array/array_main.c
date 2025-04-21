#include<stdio.h>
#include<stdint.h>

int main(void)
{
    uint8_t someData[10] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};

    printf("Contents of this array before modification:\n");

    for(uint32_t i = 0; i < 10; i++)
    {
        printf("%x\t", someData[i]);
    }

    printf("\n");

    printf("Contents of this array after modification:\n");
    
    for(uint32_t i = 0; i < 10; i++)
    {
        someData[i] = 0x33;
        printf("%x\t", someData[i]);
    }

    printf("\n");

    return 0;
}
