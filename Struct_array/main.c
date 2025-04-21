#include <stdio.h>
#include <stdint.h>

#define MAX_RECORDS 2

typedef struct {
    int     rollNumber;
    char    name[100];
    char    branch[50];
    char    dob[15];
    int     semester;
} StudentInfo;

StudentInfo students[MAX_RECORDS] = {
    {9876, "Ashok Kumar", "Mechanical", "12/11/1999", 7},
    {8888, "Ram Kumar",   "Computer",   "12/11/1999", 7}
};

void displayAllRecords(StudentInfo *records, int count) {
    for (int i = 0; i < count; i++) {
        printf("Student %d Roll Number: %d\n", i + 1, records[i].rollNumber);
    }
}

int main() {
    displayAllRecords(students, MAX_RECORDS);
    return 0;
}
