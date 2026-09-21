#include <stdio.h>

typedef struct student {
    char name[50];
    int RN;
    float cgpa;
} student;

void insert(student s[], int *n) {
    if (*n >= 100) {
        printf("Database is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%49s", s[*n].name);
    printf("Enter Roll no: ");
    scanf("%d", &s[*n].RN);
    printf("Enter CGPA: ");
    scanf("%f", &s[*n].cgpa);

    (*n)++;
}

void display(student s[], int n) {
    if (n == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("\nRoll No.\tName\tCGPA\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%s\t%.2f\n", s[i].RN, s[i].name, s[i].cgpa);
}

void search(student s[], int n) {
    int rn;

    printf("Enter Roll no to search: ");
    scanf("%d", &rn);

    for (int i = 0; i < n; i++) {
        if (s[i].RN == rn) {
            printf("Found: %d %s %.2f\n",
                   s[i].RN, s[i].name, s[i].cgpa);
            return;
        }
    }

    printf("Student not found!\n");
}

void sort(student s[], int n) {
    student temp;

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (s[j].RN > s[j + 1].RN) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }

    printf("Students sorted by Roll No.!\n");
}

void deleteStudent(student s[], int *n) {
    int rn;

    printf("Enter Roll no to delete: ");
    scanf("%d", &rn);

    for (int i = 0; i < *n; i++) {
        if (s[i].RN == rn) {
            for (int j = i; j < *n - 1; j++)
                s[j] = s[j + 1];

            (*n)--;
            printf("Student deleted!\n");
            return;
        }
    }

    printf("Student not found!\n");
}

int main() {
    student s[100];
    int n = 0, choice;

    while (1) {
        printf("\n1.Insert\n2.Display\n3.Search\n4.Sort\n5.Delete\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(s, &n); break;
            case 2: display(s, n); break;
            case 3: search(s, n); break;
            case 4: sort(s, n); break;
            case 5: deleteStudent(s, &n); break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}