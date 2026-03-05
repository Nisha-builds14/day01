#include <stdio.h>
#include <stdlib.h>

struct Contact {
    char name[50];
    char phone[15];
};

int main() {
    struct Contact contacts[5];
    int n = 0;
    int choice, i;

    char location[100];

    while(1) {
        printf("\n--- WOMEN SAFETY SYSTEM ---\n");
        printf("1. Add Emergency Contact\n");
        printf("2. View Contacts\n");
        printf("3. Activate SOS Alert\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        switch(choice) {

        case 1:
            printf("Enter Contact Name: ");
            scanf("%s",contacts[n].name);

            printf("Enter Phone Number: ");
            scanf("%s",contacts[n].phone);

            n++;
            printf("Contact added successfully\n");
            break;

        case 2:
            printf("\nTrusted Contacts:\n");
            for(i=0;i<n;i++) {
                printf("%s - %s\n",contacts[i].name,contacts[i].phone);
            }
            break;

        case 3:
            printf("Enter your location: ");
            scanf("%s",location);

            printf("\n SOS ALERT ACTIVATED \n");
            printf("Location: %s\n",location);

            for(i=0;i<n;i++) {
                printf("\nCalling %s (%s)...\n",contacts[i].name,contacts[i].phone);
                printf("Phone ringing... (1)\n");
                printf("Phone ringing... (2)\n");
            }

            printf("\nAlert sent to all trusted contacts!\n");
            break;

        case 4:
            exit(0);

        default:
            printf("Invalid choice\n");
        }
    }


}
