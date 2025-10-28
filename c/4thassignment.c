#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
    float marks;
};

void insertRecords(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        
        printf("ID: ");
        scanf("%d", &students[i].id);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Age: ");
        scanf("%d", &students[i].age);

        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void displayRecords(struct Student students[], int n) {
    printf("\nStudent Records:\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

void modifyRecord(struct Student students[], int n) {
    int id, found = 0;

    printf("\nEnter the ID of the student to modify: "); 
    scanf("%d", &id);
   

    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            found = 1;

            printf("\nCurrent details of Student ID %d:\n", id);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            printf("Marks: %.2f\n", students[i].marks);

            printf("\nEnter new details for the student:\n");

            printf("New Name: ");
            scanf(" %[^\n]", students[i].name);

            printf("New Age: ");
            scanf("%d", &students[i].age);

            printf("New Marks: ");
            scanf("%f", &students[i].marks);

            printf("\nRecord updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("\nStudent with ID %d not found.\n", id);
    }
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    insertRecords(students, n);
    displayRecords(students, n);
    modifyRecord(students, n);
    displayRecords(students, n);

    return 0;
}
