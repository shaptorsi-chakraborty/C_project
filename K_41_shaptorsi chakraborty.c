#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Customer
{
    int accountNumber;
    char name[100];
    float balance;
};
void createAccount(struct Customer *customers, int *count)
{
    if (*count >= 100)
    {
        printf("Customer Database is full. Cannot Create more Accounts.\n");
        return;
    }
    struct Customer newCustomer;
    printf("Enter Customer Details:\n");
    printf("Account Number: ");
    scanf("%d", &newCustomer.accountNumber);
    printf("Customer Name: ");
    scanf(" %[^\n]", newCustomer.name);
    printf("Initial Balance: ");
    scanf("%f", &newCustomer.balance);
    customers[*count] = newCustomer;
    (*count)++;
    printf("Account created successfully.\n");
}
void deposit(struct Customer *customers, int count)
{
    int accountNumber;
    float amount;
    int found = 0;
    printf("Enter the Account Number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < count; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);
            customers[i].balance += amount;
            printf("Amount deposited successfully.\n");
            printf("Updated Balance: %.2f\n", customers[i].balance);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Account not found.\n");
    }
}
void withdraw(struct Customer *customers, int count)
{
    int accountNumber;
    float amount;
    int found = 0;
    printf("Enter the Account Number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < count; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > customers[i].balance)
            {
                printf("Insufficient Balance.\n");
            }
            else
            {
                customers[i].balance -= amount;
                printf("Amount withdrawn successfully.\n");
                printf("Updated Balance: %.2f\n", customers[i].balance);
            }
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Account not found.\n");
    }
}
void viewBalance(struct Customer *customers, int count)
{
    int accountNumber;
    int found = 0;
    printf("Enter the Account Number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < count; i++)
    {
        if (customers[i].accountNumber == accountNumber)
        {
            printf("Account Number: %d\n", customers[i].accountNumber);
            printf("Customer Name: %s\n", customers[i].name);
            printf("Current Balance: %.2f\n", customers[i].balance);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Account not found.\n");
    }
}
int main()
{
    struct Customer customers[100];
    int count = 0;
    int choice;
    printf("Bank Management System\n");
    while (1)
    {
        printf("Hey there! I am Aman Verma from Bank Management System.");
        printf("\nSelect an Option:\n");
        printf("1. Create an Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. View Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            createAccount(customers, &count);
            break;
        case 2:
            deposit(customers, count);
            break;
        case 3:
            withdraw(customers, count);
            break;
        case 4:
            viewBalance(customers, count);
            break;
        case 5:
            printf("Thank you for using the Bank Management System.\n");
            exit(0);
        default:
            printf("Invalid Choice. Please try again.\n");
        }
    }
    return 0;
}
