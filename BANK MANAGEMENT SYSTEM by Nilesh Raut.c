//Bank Management System by Nilesh Raut

#include <stdio.h>

struct Bank {
    int acc_no;
    char name[50];
    float balance;
};

int main() {
   printf("  Bank of Indapur - Developed by Nilesh Raut\n");
    int choice, search_acc, found;
    struct Bank b;
    FILE *fp;
    int running = 1;

    while (running) {
    	 
        printf("\n    SIMPLE BANK SYSTEM \n");
        printf("1. Create Account (Save to File)\n");
        printf("2. View Account Details\n");
        printf("3. Exit\n");
        printf("Enter your choice: (1/2/3) ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fp = fopen("bank_data.txt", "a");
                if (fp == NULL) {
                    printf("File Error!\n");
                    break;
                }

                printf("Enter Account Number: ");
                scanf("%d", &b.acc_no);
                printf("Enter Name of Account Holder: ");
                scanf("%s", b.name);
                printf("Enter Initial Account Balance: ");
                scanf("%f", &b.balance);

                fprintf(fp, "%d %s %.2f\n", b.acc_no, b.name, b.balance);
                fclose(fp);

                printf("\nACCOUNT CREATED SUCCESSFULLY!\n");
                break;

            case 2:
                fp = fopen("bank_data.txt", "r");
                if (fp == NULL) {
                    printf("\nNo account records found!\nCreate an account first.\n");
                    break;
                }

                printf("Enter Account Number to search: ");
                scanf("%d", &search_acc);
                found = 0;

                while (fscanf(fp, "%d %s %f", &b.acc_no, b.name, &b.balance) == 3) {
                    if (b.acc_no == search_acc) {
                        printf("\n___ ACCOUNT FOUND ___ \n");
                        printf("Account Number : %d\n", b.acc_no);
                        printf("Name           : %s\n", b.name);
                        printf("Balance        : %.2f\n", b.balance);
                        found = 1;
                        break;
                    }
                }
                fclose(fp);

                if (!found) {
                    printf("\nAccount number %d not found!\n", search_acc);
                }
                break;

            case 3:
                printf("\nThank you for using Bank Management System by Nilesh Raut!\n");
                running = 0;
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
