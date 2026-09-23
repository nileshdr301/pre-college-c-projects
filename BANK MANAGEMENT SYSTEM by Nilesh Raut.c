//Bank Management System by Nilesh Raut

#include <stdio.h>

struct Bank {
    int acc_no;
    char name[50];
    float balance;
    int pin; 
};

int main() {
    printf("  Bank of Indapur - Developed by Nilesh Raut\n");
    int choice, search_acc, found, entered_pin;
    struct Bank b;
    FILE *fp, *temp;
    int running = 1;
    float amount;

    while (running) {
        printf("\n    SIMPLE BANK SYSTEM \n");
        printf("1. Create Account \n");
        printf("2. View Account Details\n");
        printf("3. Deposit Cash\n");
        printf("4. Withdraw Cash\n");
        printf("5. Exit\n");
        printf("Enter your choice: (1-5) ");
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
                printf("Set a 4-digit PIN: ");
                scanf("%d", &b.pin);

                fprintf(fp, "%d %s %.2f %d\n", b.acc_no, b.name, b.balance, b.pin);
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

                while (fscanf(fp, "%d %s %f %d", &b.acc_no, b.name, &b.balance, &b.pin) == 4) {
                    if (b.acc_no == search_acc) {
                        printf("Enter your 4-digit PIN: ");
                        scanf("%d", &entered_pin);
                        
                        if (b.pin == entered_pin) {
                            printf("\n___ ACCOUNT FOUND ___ \n");
                            printf("Account Number : %d\n", b.acc_no);
                            printf("Name           : %s\n", b.name);
                            printf("Balance        : %.2f\n", b.balance);
                        } else {
                            printf("\nIncorrect PIN! Access Denied.\n");
                        }
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
                fp = fopen("bank_data.txt", "r");
                if (fp == NULL) {
                    printf("\nNo account records found!\n");
                    break;
                }
                temp = fopen("temp.txt", "w");
                if (temp == NULL) {
                    printf("File Error!\n");
                    fclose(fp);
                    break;
                }

                printf("Enter Account Number for Deposit: ");
                scanf("%d", &search_acc);
                found = 0;

                while (fscanf(fp, "%d %s %f %d", &b.acc_no, b.name, &b.balance, &b.pin) == 4) {
                    if (b.acc_no == search_acc) {
                        found = 1;
                        printf("Enter your 4-digit PIN: ");
                        scanf("%d", &entered_pin);

                        if (b.pin == entered_pin) {
                            printf("Enter amount to deposit: ");
                            scanf("%f", &amount);
                            if (amount > 0) {
                                b.balance += amount;
                                printf("\nDEPOSIT SUCCESSFUL! Updated Balance: %.2f\n", b.balance);
                            } else {
                                printf("\nInvalid amount!\n");
                            }
                        } else {
                            printf("\nIncorrect PIN! Transaction Cancelled.\n");
                        }
                    }
                    fprintf(temp, "%d %s %.2f %d\n", b.acc_no, b.name, b.balance, b.pin);
                }
                fclose(fp);
                fclose(temp);

                remove("bank_data.txt");
                rename("temp.txt", "bank_data.txt");

                if (!found) {
                    printf("\nAccount number %d not found!\n", search_acc);
                }
                break;

            case 4: 
                fp = fopen("bank_data.txt", "r");
                if (fp == NULL) {
                    printf("\nNo account records found!\n");
                    break;
                }
                temp = fopen("temp.txt", "w");
                if (temp == NULL) {
                    printf("File Error!\n");
                    fclose(fp);
                    break;
                }

                printf("Enter Account Number for Withdrawal: ");
                scanf("%d", &search_acc);
                found = 0;

                while (fscanf(fp, "%d %s %f %d", &b.acc_no, b.name, &b.balance, &b.pin) == 4) {
                    if (b.acc_no == search_acc) {
                        found = 1;
                        printf("Enter your 4-digit PIN: ");
                        scanf("%d", &entered_pin);

                        if (b.pin == entered_pin) {
                            printf("Enter amount to withdraw: ");
                            scanf("%f", &amount);
                            if (amount > 0) {
                                if (b.balance >= amount) {
                                    b.balance -= amount;
                                    printf("\nWITHDRAWAL SUCCESSFUL! Updated Balance: %.2f\n", b.balance);
                                } else {
                                    printf("\nInsufficient balance!\n");
                                }
                            } else {
                                printf("\nInvalid amount!\n");
                            }
                        } else {
                            printf("\nIncorrect PIN! Transaction Cancelled.\n");
                        }
                    }
                    fprintf(temp, "%d %s %.2f %d\n", b.acc_no, b.name, b.balance, b.pin);
                }
                fclose(fp);
                fclose(temp);

                remove("bank_data.txt");
                rename("temp.txt", "bank_data.txt");

                if (!found) {
                    printf("\nAccount number %d not found!\n", search_acc);
                }
                break;

            case 5:
                printf("\nThank you for using Bank Management System by Nilesh Raut!\n");
                running = 0;
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
