#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct AcademicRecord {
    int studentId;
    char fullName[50];
    float finalGrade;
};

void registerNewStudent(struct AcademicRecord* recordsArray, int* totalCount, int maxCapacity) {
    if (*totalCount >= maxCapacity) {
        printf("Memory full.\n");
        return;
    }
    struct AcademicRecord* currentStudent = recordsArray + *totalCount;
    printf("Enter ID: ");
    scanf("%d", &(currentStudent->studentId));
    printf("Enter Name: ");
    scanf(" %[^\n]", currentStudent->fullName);
    printf("Enter Grade: ");
    scanf("%f", &(currentStudent->finalGrade));
    (*totalCount)++;
}

void displayAllRecords(struct AcademicRecord* recordsArray, int totalCount) {
    printf("\nStudent ID: 54321\n");
    printf("Analysis Function: Performance Classification\n");
    printf("ID\tName\t\tGrade\n");
    struct AcademicRecord* currentStudent = recordsArray;
    for (int i = 0; i < totalCount; i++) {
        printf("%d\t%s\t\t%.2f\n", currentStudent->studentId, currentStudent->fullName, currentStudent->finalGrade);
        currentStudent++;
    }
}

void sortRecordsByGrade(struct AcademicRecord* recordsArray, int totalCount) {
    struct AcademicRecord tempRecord;
    for (int i = 0; i < totalCount - 1; i++) {
        for (int j = 0; j < totalCount - i - 1; j++) {
            struct AcademicRecord* current = recordsArray + j;
            struct AcademicRecord* next = recordsArray + j + 1;
            if (current->finalGrade < next->finalGrade) {
                tempRecord = *current;
                *current = *next;
                *next = tempRecord;
            }
        }
    }
    printf("Records sorted successfully.\n");
}

void computeClassAverage(struct AcademicRecord* recordsArray, int totalCount) {
    if (totalCount == 0) return;
    float totalSum = 0.0;
    struct AcademicRecord* currentStudent = recordsArray;
    for (int i = 0; i < totalCount; i++) {
        totalSum += currentStudent->finalGrade;
        currentStudent++;
    }
    printf("Class Average: %.2f\n", totalSum / totalCount);
}

void identifyTopPerformer(struct AcademicRecord* recordsArray, int totalCount) {
    if (totalCount == 0) return;
    struct AcademicRecord* topStudent = recordsArray;
    struct AcademicRecord* currentStudent = recordsArray;
    for (int i = 0; i < totalCount; i++) {
        if (currentStudent->finalGrade > topStudent->finalGrade) {
            topStudent = currentStudent;
        }
        currentStudent++;
    }
    printf("Top Performer: %s with %.2f\n", topStudent->fullName, topStudent->finalGrade);
}

void classifyPerformanceStatus(struct AcademicRecord* recordsArray, int totalCount) {
    struct AcademicRecord* currentStudent = recordsArray;
    printf("\nPerformance Classification:\n");
    for (int i = 0; i < totalCount; i++) {
        char status = 'F';
        if (currentStudent->finalGrade >= 90.0) status = 'A';
        else if (currentStudent->finalGrade >= 80.0) status = 'B';
        else if (currentStudent->finalGrade >= 70.0) status = 'C';
        else if (currentStudent->finalGrade >= 60.0) status = 'D';
        
        printf("%s: %c\n", currentStudent->fullName, status);
        currentStudent++;
    }
}

int main() {
    int maxStudents = 20;
    int currentCount = 0;
    struct AcademicRecord* classroom = (struct AcademicRecord*)malloc(maxStudents * sizeof(struct AcademicRecord));
    
    void (*operationPointers[7])(struct AcademicRecord*, int) = {
        NULL, 
        NULL, 
        displayAllRecords, 
        sortRecordsByGrade, 
        computeClassAverage, 
        identifyTopPerformer, 
        classifyPerformanceStatus
    };

    int userChoice = 0;
    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Sort Students\n4. Calculate Average\n5. Find Top Student\n6. Perform Classification Analysis\n7. Exit\nChoice: ");
        scanf("%d", &userChoice);
        
        if (userChoice == 7) break;
        
        if (userChoice == 1) {
            registerNewStudent(classroom, &currentCount, maxStudents);
        } else if (userChoice >= 2 && userChoice <= 6) {
            operationPointers[userChoice](classroom, currentCount);
        } else {
            printf("Invalid choice.\n");
        }
    }
    
    free(classroom);
    return 0;
}
