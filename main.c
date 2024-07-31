#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

typedef struct Transaction {
    char date[11];
    char type[10];
    char category[20];
    double amount;
    struct Transaction *next;
} Transaction;

Transaction* create_transaction(char *input) {
    Transaction *new_transaction = (Transaction*)malloc(sizeof(Transaction));
    
    // Tokenize the input string
    char *token = strtok(input, " ");
    strcpy(new_transaction->date, token);
    
    token = strtok(NULL, " ");
    strcpy(new_transaction->type, token);
    
    token = strtok(NULL, " ");
    strcpy(new_transaction->category, token);
    
    token = strtok(NULL, " ");
    new_transaction->amount = atof(token);
    
    new_transaction->next = NULL;
    
    return new_transaction;
}

void add_transaction(Transaction **head, char *input) {
    Transaction *new_transaction = create_transaction(input);
    
    if (*head == NULL) {
        *head = new_transaction;
    } else {
        Transaction *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_transaction;
    }
}

double calculate_balance(Transaction *head) {
    double balance = 0.0;
    Transaction *current = head;
    
    while (current != NULL) {
        if (strcmp(current->type, "income") == 0) {
            balance += current->amount;
        } else if (strcmp(current->type, "expense") == 0) {
            balance -= current->amount;
        }
        current = current->next;
    }
    
    return balance;
}

void generate_report(Transaction *head) {
    FILE *file = fopen("report.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    Transaction *current = head;
    fprintf(file, "Date        Type     Category   Amount\n");
    fprintf(file, "---------------------------------------\n");
    while (current != NULL) {
        fprintf(file, "%s  %s  %s  %.2f\n", current->date, current->type, current->category, current->amount);
        current = current->next;
    }
    
    fclose(file);
    printf("Report generated and saved to 'report.txt'.\n");
}

void save_data(Transaction *head) {
    FILE *file = fopen("transactions.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    
    Transaction *current = head;
    while (current != NULL) {
        fprintf(file, "%s %s %s %.2f\n", current->date, current->type, current->category, current->amount);
        current = current->next;
    }
    
    fclose(file);
    printf("Data saved to 'transactions.txt'.\n");
}

void load_data(Transaction **head) {
    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL) {
        printf("No previous data found.\n");
        return;
    }
    
    char input[MAX_INPUT_LENGTH];
    while (fgets(input, MAX_INPUT_LENGTH, file) != NULL) {
        input[strcspn(input, "\n")] = 0;
        add_transaction(head, input);
    }
    
    fclose(file);
    printf("Data loaded from 'transactions.txt'.\n");
}

void display_transactions(Transaction *head) {
    Transaction *current = head;
    if (current == NULL) {
        printf("No transactions available.\n");
        return;
    }

    while (current != NULL) {
        printf("Date: %s\n", current->date);
        printf("Type: %s\n", current->type);
        printf("Category: %s\n", current->category);
        printf("Amount: %.2f\n", current->amount);
        printf("---------------------------------------\n");
        current = current->next;
    }
}

void display_menu() {
    printf("\nFinance Tracker Menu:\n");
    printf("1. Add Transaction\n");
    printf("2. Calculate Balance\n");
    printf("3. Generate Report\n");
    printf("4. Display All Transactions\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    Transaction *head = NULL;
    char input[MAX_INPUT_LENGTH];
    int choice;
    
    // Load existing data
    load_data(&head);
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character
        
        switch (choice) {
            case 1:
                printf("Enter transaction (date(YYYY-MM-DD)  type(income/expense)  category(e.g food , rent ,etc) amount):\n");
                fgets(input, MAX_INPUT_LENGTH, stdin);
                input[strcspn(input, "\n")] = 0;  // Remove newline character
                add_transaction(&head, input);
                break;
            case 2:
                printf("\nBalance: %.2f\n", calculate_balance(head));
                break;
            case 3:
                printf("\nGenerating Report...\n");
                generate_report(head);
                break;
            case 4:
                printf("\nDisplaying All Transactions...\n \n");
                display_transactions(head);
                break;
            case 5:
                printf("Exiting and saving data...\n");
                save_data(head);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
