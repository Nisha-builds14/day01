#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll;
    char name[50];
    float marks;
};

int main() {
    FILE *fp;
    struct student s;
    int choice, found = 0;
    int searchRoll;

    while(1) {
        printf("\n--- STUDENT MENU ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

        case 1:
            fp = fopen("student.txt", "a");

            printf("Enter Roll: ");
            scanf("%d", &s.roll);

            printf("Enter Name: ");
            scanf("%s", s.name);

            printf("Enter Marks: ");
            scanf("%f", &s.marks);

            fprintf(fp,"%d %s %f\n", s.roll, s.name, s.marks);
            fclose(fp);

            printf("Student added successfully\n");
            break;

        case 2:
            fp = fopen("student.txt", "r");

            printf("\nRoll   Name   Marks\n");

            while(fscanf(fp,"%d %s %f",&s.roll,s.name,&s.marks)!=EOF) {
                printf("%d   %s   %.2f\n",s.roll,s.name,s.marks);
            }

            fclose(fp);
            break;

        case 3:
            printf("Enter roll to search: ");
            scanf("%d",&searchRoll);

            fp = fopen("student.txt","r");

            while(fscanf(fp,"%d %s %f",&s.roll,s.name,&s.marks)!=EOF) {
                if(s.roll == searchRoll) {
                    printf("Found: %d %s %.2f\n",s.roll,s.name,s.marks);
                    found = 1;
                }
            }

            if(!found)
                printf("Student not found\n");

            fclose(fp);
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}

