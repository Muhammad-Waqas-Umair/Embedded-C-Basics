
#include<stdint.h>
#include<stdio.h>

struct carModel
{
	uint8_t carSpeed;
	uint32_t carPrice;
};

int main(void)
{
	struct carModel  carBMW = {220, 25000};
	printf("Sizeof of struct carModel is %I64u\n",sizeof(struct carModel));


	return 0;
}