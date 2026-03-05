#include <stdio.h>

struct Bank {
    int accNo;
    char name[50];
    float balance;
};

int main() {
    struct Bank user;
    int choice;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &user.accNo);

    printf("Enter Account Holder Name: ");
    scanf("%s", user.name);

    user.balance = 0;

    while(1) {
        printf("\n--- BANK MENU ---\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                user.balance += amount;
                printf("Amount deposited successfully\n");
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if(amount > user.balance) {
                    printf("Insufficient balance\n");
                } else {
                    user.balance -= amount;
                    printf("Withdrawal successful\n");
                }
                break;

            case 3:
                printf("Account Number: %d\n", user.accNo);
                printf("Account Holder: %s\n", user.name);
                printf("Balance: %.2f\n", user.balance);
                break;

            case 4:
                printf("Thank you for using bank system\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
