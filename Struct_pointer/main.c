#include <stdint.h>
#include <stdio.h>

struct Record {
    char field1;
    int field2;
    char field3;
    short field4;
};

void displayRecordFields(struct Record *record);

int main(void) {

    struct Record record;

    record.field1 = 0x11;
    record.field2 = 0xFFFFEEEE;
    record.field3 = 0x22;
    record.field4 = 0xABCD;

    // Passing the address of the record to the function
    displayRecordFields(&record);

    getchar();

    return 0;
}

void displayRecordFields(struct Record *record) {
    // Accessing the fields through the pointer
    printf("field1 = %X\n", record->field1);
    printf("field2 = %X\n", record->field2);
    printf("field3 = %X\n", record->field3);
    printf("field4 = %X\n", record->field4);
}
