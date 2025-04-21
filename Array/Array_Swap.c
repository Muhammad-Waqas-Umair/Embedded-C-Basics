#include <stdio.h>
#include <stdint.h>

#define MAX_ITEMS 1000

void wait_for_user_input(void);
void display_array(int32_t *pArray1, uint32_t nitem);
void swap_arrays(int32_t *array1, int32_t *array2, uint32_t nitem1, uint32_t nitem2);

int main(void) {
    int32_t nItem1, nItem2;

    printf("Array swapping program\n");
    printf("Enter the number of elements for Array-1 and Array-2: ");

    if (scanf("%d %d", &nItem1, &nItem2) != 2) {
        printf("Invalid input! Please enter two integers.\n");
        wait_for_user_input();
        return 0;
    }

    while (getchar() != '\n'); 

    if ((nItem1 < 0) || (nItem2 < 0)) {
        printf("Number of elements cannot be negative\n");
        wait_for_user_input();
        return 0;
    }

    if ((nItem1 > MAX_ITEMS) || (nItem2 > MAX_ITEMS)) {
        printf("Number of elements exceeds maximum limit (%d)\n", MAX_ITEMS);
        wait_for_user_input();
        return 0;
    }

    int32_t array1[nItem1];
    int32_t array2[nItem2];

    for (uint32_t i = 0; i < nItem1; i++) {
        printf("Enter element %d of array1: ", i);
        if (scanf("%d", &array1[i]) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            wait_for_user_input();
            return 0;
        }
    }

    for (uint32_t i = 0; i < nItem2; i++) {
        printf("Enter element %d of array2: ", i);
        if (scanf("%d", &array2[i]) != 1) {
            printf("Invalid input! Please enter an integer.\n");
            wait_for_user_input();
            return 0;
        }
    }

    printf("Contents of arrays before swap:\n");
    display_array(array1, nItem1);
    display_array(array2, nItem2);

    printf("\nContents of arrays after swap:\n");
    swap_arrays(array1, array2, nItem1, nItem2);
    display_array(array1, nItem1);
    display_array(array2, nItem2);

    wait_for_user_input();
    return 0;
}

void display_array(int32_t *pArray1, uint32_t nitem) {
    if (nitem == 0) {
        printf("Array is empty.\n");
        return;
    }
    for (uint32_t i = 0; i < nitem; i++) {
        printf("%4d  ", pArray1[i]);
    }
    printf("\n");
}

void swap_arrays(int32_t *array1, int32_t *array2, uint32_t nitem1, uint32_t nitem2) {
    if (nitem1 == 0 || nitem2 == 0) {
        printf("Cannot swap empty arrays.\n");
        return;
    }

    uint32_t len = (nitem1 < nitem2) ? nitem1 : nitem2; 
    for (uint32_t i = 0; i < len; i++) {
        int32_t temp = array1[i];
        array1[i] = array2[i];
        array2[i] = temp;
    }
}

void wait_for_user_input(void) {
    printf("Press the Enter key to exit this application.");
    while (getchar() != '\n'); 
    getchar(); 
}
