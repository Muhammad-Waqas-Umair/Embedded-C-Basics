#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int buttonState = 0;
    int ledState = 0;
    int duration = 0;

    printf("Enter button state (0 = not pressed, 1 = pressed): ");
    scanf("%d", &buttonState);

    if (buttonState == 1) {
        printf("Enter the duration for the LED to stay ON (in seconds): ");
        scanf("%d", &duration);
    }

    if (buttonState == 1) {
        ledState = 1;
        printf("LED ON for %d seconds...\n", duration);
        sleep(duration);
        ledState = 0;
        printf("LED OFF\n");
    } else {
        ledState = 0;
        printf("LED OFF\n");
    }

    if (ledState == 1) {
        printf("LED is ON\n");
    } else {
        printf("LED is OFF\n");
    }

    return 0;
}
