#include<stdio.h>
#include<stdint.h>

void wait_for_user_input(void);

int main(void)
{
    float num1, num2;
    
    printf("Enter the first number (real): ");
    if (scanf("%f", &num1) != 1) {
        printf("Invalid input! Please enter a valid number.\n");
        wait_for_user_input();
        return 0;
    }

    printf("Enter the second number (real): ");
    if (scanf("%f", &num2) != 1) {
        printf("Invalid input! Please enter a valid number.\n");
        wait_for_user_input();
        return 0;
    }

    int32_t n1 = (int32_t)num1;
    int32_t n2 = (int32_t)num2;

    if (n1 != num1 || n2 != num2) {
        printf("Warning: Only the integer part of the numbers is being compared.\n");
    }

    if (n1 == n2) {
        printf("The integer parts of the numbers are equal.\n");
    } else {
        printf("The larger integer part is: %d\n", (n1 > n2) ? n1 : n2);
    }

    wait_for_user_input();
    return 0;
}

void wait_for_user_input(void)
{
    printf("Press Enter to exit the application...\n");

    while (getchar() != '\n') {
    }
    getchar();
}
