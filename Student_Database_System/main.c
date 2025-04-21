#include <stdio.h>
#include <stdint.h>
#include <string.h>

// Definition of a student record
typedef struct
{
    int id;
    char name[100];
    char department[50];
    char birthDate[15];
    int year;
} StudentRecord;

// Maximum number of records the program can store
#define MAX_RECORDS 10

// Global array to store student records
StudentRecord studentRecords[MAX_RECORDS];

// Function prototypes
void showMenu(void);
int getMenuChoice(void);
void handleMenuChoice(int choice);
void listAllRecords(StudentRecord *records, int maxRecords);
int isRollNumberExists(int rollNumber, StudentRecord *records, int maxRecords);
int addRecord(StudentRecord *records, int maxRecords);
int removeRecord(StudentRecord *records, int maxRecords);

// Main entry point of the application
int main()
{
    int choice;
    int continueApp = 1;

    printf("Student Record Management System\n");

    while (continueApp)
    {
        // Display the menu
        showMenu();

        // Get the user's choice
        choice = getMenuChoice();

        if (choice)
        {
            // Handle the user's choice
            handleMenuChoice(choice);
        }
        else
        {
            // Exit the application if the choice is 0
            continueApp = 0;
            printf("Exiting application...\n");
        }
    }

    return 0;
}

// Function to display the menu options
void showMenu(void)
{
    printf("1. Display all records\n");
    printf("2. Add a new record\n");
    printf("3. Delete a record\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

// Function to read and return the user's menu choice
int getMenuChoice(void)
{
    int input;
    scanf("%d", &input);
    return input;
}

// Function to handle the user's menu choice
void handleMenuChoice(int choice)
{
    int result;

    switch (choice)
    {
        case 1:
            printf("Displaying all student records...\n");
            listAllRecords(studentRecords, MAX_RECORDS);
            break;

        case 2:
            printf("Adding a new student record...\n");
            result = addRecord(studentRecords, MAX_RECORDS);
            if (result)
                printf("Record added successfully.\n");
            else
                printf("Failed to add record.\n");
            break;

        case 3:
            printf("Deleting a student record...\n");
            result = removeRecord(studentRecords, MAX_RECORDS);
            if (result)
                printf("Record deleted successfully.\n");
            else
                printf("Record not found.\n");
            break;

        default:
            printf("Invalid input. Please try again.\n");
    }
}

// Function to display all student records
void listAllRecords(StudentRecord *records, int maxRecords)
{
    int recordFound = 0;

    for (int i = 0; i < maxRecords; i++)
    {
        if (records[i].id)
        {
            recordFound = 1;
            printf("***********\n");
            printf("ID: %d\n", records[i].id);
            printf("Year: %d\n", records[i].year);
            printf("Date of Birth: %s\n", records[i].birthDate);
            printf("Department: %s\n", records[i].department);
            printf("Name: %s\n", records[i].name);
            printf("***********\n");
        }
    }

    if (!recordFound)
        printf("No records found.\n");
}

// Function to check if a roll number already exists
int isRollNumberExists(int rollNumber, StudentRecord *records, int maxRecords)
{
    for (int i = 0; i < maxRecords; i++)
    {
        if (records[i].id == rollNumber)
            return 1;
    }
    return 0;
}

// Function to add a new student record
int addRecord(StudentRecord *records, int maxRecords)
{
    int rollNumber;
    int addedSuccessfully = 0;

    for (int i = 0; i < maxRecords; i++)
    {
        if (!records[i].id)
        {
            printf("Enter student ID: ");
            scanf("%d", &rollNumber);

            if (!isRollNumberExists(rollNumber, records, maxRecords))
            {
                records[i].id = rollNumber;
                printf("Enter student year: ");
                scanf("%d", &records[i].year);
                printf("Enter student birth date (mm/dd/yyyy): ");
                scanf("%s", records[i].birthDate);
                getchar(); // To consume the newline left by scanf
                printf("Enter student department: ");
                scanf("%50[^\n]", records[i].department);
                getchar();
                printf("Enter student name: ");
                scanf("%50[^\n]", records[i].name);

                addedSuccessfully = 1;
            }
            else
            {
                printf("Roll number already exists.\n");
            }

            break;
        }
    }

    if (!addedSuccessfully)
        printf("No space available to add a new record.\n");

    return addedSuccessfully;
}

// Function to remove a student record based on the ID
int removeRecord(StudentRecord *records, int maxRecords)
{
    int rollNumber;
    printf("Enter the student ID to delete: ");
    scanf("%d", &rollNumber);

    for (int i = 0; i < maxRecords; i++)
    {
        if (records[i].id == rollNumber)
        {
            memset(&records[i], 0, sizeof(StudentRecord));
            return 1; // Record successfully deleted
        }
    }

    return 0; // Record not found
}
