#include <stdio.h>
#include <stdint.h>

uint16_t fake_value = 100;

uint16_t read_sensor(void)
{
    return fake_value += 25;
}

void reset_sensor(void)
{
    fake_value = 100;
}

void wait_for_user_input(void)
{
    printf("\nPress Enter key to exit the application...");
    while (getchar() != '\n');
    getchar();
}

int main(void)
{
    uint16_t sensor_value;

    printf("Memory address of fake_value: %p\n", (void*)&fake_value);

    // FOR loop - Read sensor value 3 times
    printf("=== Sensor Readings with FOR loop ===\n");
    for (uint8_t i = 0; i < 3; i++)
    {
        sensor_value = read_sensor();
        printf("Reading %d: %u\n", i + 1, sensor_value);
    }

    reset_sensor();
    printf("\n");

    // WHILE loop - Read sensor value 3 times
    printf("=== Sensor Readings with WHILE loop ===\n");
    uint8_t j = 0;
    while (j < 3)
    {
        sensor_value = read_sensor();
        printf("Reading %d: %u\n", j + 1, sensor_value);
        j++;
    }

    reset_sensor();
    printf("\n");

    // DO-WHILE loop - Read sensor value 3 times
    printf("=== Sensor Readings with DO-WHILE loop ===\n");
    uint8_t k = 0;
    do
    {
        sensor_value = read_sensor();
        printf("Reading %d: %u\n", k + 1, sensor_value);
        k++;
    } while (k < 3);

    wait_for_user_input();
    return 0;
}
