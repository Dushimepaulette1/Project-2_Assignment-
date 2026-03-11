#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float grade;
};

void add_students(struct Student* recordsArray, int* totalCount, int maxCapacity) {
    if (*totalCount >= maxCapacity) {
        printf("Memory full.\n");
        return;
    }
    struct Student* currentStudent = recordsArray + *totalCount;
    printf("Enter ID: ");
    scanf("%d", &(currentStudent->id));
    printf("Enter Name: ");
    scanf(" %[^\n]", currentStudent->name);
    printf("Enter Grade: ");
    scanf("%f", &(currentStudent->grade));
    (*totalCount)++;
}

void display_students(struct Student* recordsArray, int totalCount) {
    printf("\nStudent ID: 22\n");
    printf("Analysis Function: Performance Classification\n");
    printf("ID\tName\t\t\tGrade\n");
    struct Student* currentStudent = recordsArray;
    for (int i = 0; i < totalCount; i++) {
        printf("%d\t%-20s\t%.2f\n", currentStudent->id, currentStudent->name, currentStudent->grade);
        currentStudent++;
    }
}

void sort_students(struct Student* recordsArray, int totalCount) {
    struct Student tempRecord;
    for (int i = 0; i < totalCount - 1; i++) {
        for (int j = 0; j < totalCount - i - 1; j++) {
            struct Student* current = recordsArray + j;
            struct Student* next = recordsArray + j + 1;

            if (strcmp(current->name, next->name) > 0) {
                tempRecord = *current;
                *current = *next;
                *next = tempRecord;
            }
        }
    }
    printf("Records sorted alphabetically successfully.\n");
}

void calculate_average(struct Student* recordsArray, int totalCount) {
    if (totalCount == 0) return;
    float totalSum = 0.0;
    struct Student* currentStudent = recordsArray;
    for (int i = 0; i < totalCount; i++) {
        totalSum += currentStudent->grade;
        currentStudent++;
    }
    printf("Class Average: %.2f\n", totalSum / totalCount);
}

void find_top_student(struct Student* recordsArray, int totalCount) {
    if (totalCount == 0) return;
    struct Student* topStudent = recordsArray;
    struct Student* currentStudent = recordsArray;
    for (int i = 0; i < totalCount; i++) {
        if (currentStudent->grade > topStudent->grade) {
            topStudent = currentStudent;
        }
        currentStudent++;
    }
    printf("Top Performer: %s with %.2f\n", topStudent->name, topStudent->grade);
}

void perform_analysis(struct Student* recordsArray, int totalCount) {
    struct Student* currentStudent = recordsArray;
    printf("\nPerformance Classification:\n");
    for (int i = 0; i < totalCount; i++) {
        char status = 'F';
        if (currentStudent->grade >= 90.0) status = 'A';
        else if (currentStudent->grade >= 80.0) status = 'B';
        else if (currentStudent->grade >= 70.0) status = 'C';
        else if (currentStudent->grade >= 60.0) status = 'D';

        printf("%s: %c\n", currentStudent->name, status);
        currentStudent++;
    }
}

int main() {
    int maxStudents = 20;
    int currentCount = 0;
    struct Student* classroom = (struct Student*)malloc(maxStudents * sizeof(struct Student));

    void (*operationPointers[7])(struct Student*, int) = {
        NULL,
        NULL,
        display_students,
        sort_students,
        calculate_average,
        find_top_student,
        perform_analysis
    };

    int userChoice = 0;
    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Sort Students\n4. Calculate Average\n5. Find Top Student\n6. Perform Classification Analysis\n7. Exit\nChoice: ");
        scanf("%d", &userChoice);

        if (userChoice == 7) break;

        if (userChoice == 1) {
            add_students(classroom, &currentCount, maxStudents);
        } else if (userChoice >= 2 && userChoice <= 6) {
            operationPointers[userChoice](classroom, currentCount);
        } else {
            printf("Invalid choice.\n");
        }
    }

    free(classroom);
    return 0;
}
