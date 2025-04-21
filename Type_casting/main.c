#include<stdio.h>

int main(void)
{
   unsigned long long data = (unsigned long long)0x1FFFFFFFA0B0 + (unsigned long long)0x1245;

   float result = (float)80 / (float)3;

   printf("Data: %llu  Result: %f\n", data, result);

   return 0;
}
