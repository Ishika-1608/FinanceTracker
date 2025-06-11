#include <stdio.h>
#include <string.h>

// Constants for transaction array and string lengths
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORY_LENGTH 20

// Struct to store transaction details
typedef struct {
    float amount;
    char category[MAX_CATEGORY_LENGTH];
    char type[8]; // "Income" or "Expense"
} Transaction;

// Function to clear input buffer (handles leftover characters)
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Personal Finance Tracker ===\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Balance\n");
    printf("4. View Transaction History\n");
    printf("5. View Summary Report\n");
    printf("6. Exit\n");
    printf("Enter your choice (1-6): ");
}

// Function to load transactions from file
void loadTransactions(Transaction transactions[], int *transactionCount, float *balance) {
    FILE *file = fopen("transactions.txt", "r");
    *transactionCount = 0; // Reset count
    *balance = 0.0; // Reset balance

    if (file == NULL) {
        // File doesn't exist yet (first run), start with empty state
        return;
    }

    while (*transactionCount < MAX_TRANSACTIONS) {
        char type[8];
        float amount;
        char category[MAX_CATEGORY_LENGTH];

        // Read one transaction (type, amount, category)
        if (fscanf(file, "%7s %f %19s", type, &amount, category) != 3) {
            break; // End of file or error
        }

        // Store transaction
        transactions[*transactionCount].amount = amount;
        strncpy(transactions[*transactionCount].category, category, MAX_CATEGORY_LENGTH - 1);
        transactions[*transactionCount].category[MAX_CATEGORY_LENGTH - 1] = '\0';
        strncpy(transactions[*transactionCount].type, type, 7);
        transactions[*transactionCount].type[7] = '\0';

        // Update balance based on type
        if (strcmp(type, "Income") == 0) {
            *balance += amount;
        } else if (strcmp(type, "Expense") == 0) {
            *balance -= amount;
        }

        (*transactionCount)++;
    }

    fclose(file);
}

// Function to save transactions to file
void saveTransactions(Transaction transactions[], int transactionCount) {
    FILE *file = fopen("transactions.txt", "w");
    if (file == NULL) {
        printf("Error: Could not save transactions to file!\n");
        return;
    }

    // Write each transaction to the file
    for (int i = 0; i < transactionCount; i++) {
        fprintf(file, "%s %.2f %s\n", transactions[i].type, transactions[i].amount, transactions[i].category);
    }

    fclose(file);
}

// Function to add income
void addIncome(float *balance, Transaction transactions[], int *transactionCount) {
    float amount;
    int category;
    char *incomeCategories[] = {"Salary", "Gift", "Other"};

    printf("\nEnter income amount: ");
    if (scanf("%f", &amount) != 1) {
        printf("Error: Invalid amount (must be a number)!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Validate amount
    if (amount <= 0) {
        printf("Error: Amount must be positive!\n");
        return;
    }

    printf("Select category:\n");
    printf("1. Salary\n2. Gift\n3. Other\n");
    printf("Enter category number (1-3): ");
    if (scanf("%d", &category) != 1) {
        printf("Error: Invalid category (must be a number)!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Validate category
    if (category < 1 || category > 3) {
        printf("Error: Invalid category!\n");
        return;
    }

    // Update balance and store transaction
    if (*transactionCount < MAX_TRANSACTIONS) {
        *balance += amount;
        transactions[*transactionCount].amount = amount;
        strncpy(transactions[*transactionCount].category, incomeCategories[category - 1], MAX_CATEGORY_LENGTH - 1);
        transactions[*transactionCount].category[MAX_CATEGORY_LENGTH - 1] = '\0';
        strcpy(transactions[*transactionCount].type, "Income");
        (*transactionCount)++;
        printf("Added income: $%.2f (%s)\n", amount, incomeCategories[category - 1]);
    } else {
        printf("Error: Transaction limit reached!\n");
    }
}

// Function to add expense
void addExpense(float *balance, Transaction transactions[], int *transactionCount) {
    float amount;
    int category;
    char *expenseCategories[] = {"Food", "Rent", "Utilities", "Other"};

    printf("\nEnter expense amount: ");
    if (scanf("%f", &amount) != 1) {
        printf("Error: Invalid amount (must be a number)!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Validate amount
    if (amount <= 0) {
        printf("Error: Amount must be positive!\n");
        return;
    }

    printf("Select category:\n");
    printf("1. Food\n2. Rent\n3. Utilities\n4. Other\n");
    printf("Enter category number (1-4): ");
    if (scanf("%d", &category) != 1) {
        printf("Error: Invalid category (must be a number)!\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    // Validate category
    if (category < 1 || category > 4) {
        printf("Error: Invalid category!\n");
        return;
    }

    // Update balance and store transaction
    if (*transactionCount < MAX_TRANSACTIONS) {
        *balance -= amount;
        transactions[*transactionCount].amount = amount;
        strncpy(transactions[*transactionCount].category, expenseCategories[category - 1], MAX_CATEGORY_LENGTH - 1);
        transactions[*transactionCount].category[MAX_CATEGORY_LENGTH - 1] = '\0';
        strcpy(transactions[*transactionCount].type, "Expense");
        (*transactionCount)++;
        printf("Added expense: $%.2f (%s)\n", amount, expenseCategories[category - 1]);
    } else {
        printf("Error: Transaction limit reached!\n");
    }
}

// Function to view balance
void viewBalance(float balance) {
    printf("\nCurrent Balance: $%.2f\n", balance);
}

// Function to view transaction history
void viewTransactionHistory(Transaction transactions[], int transactionCount) {
    printf("\n=== Transaction History ===\n");
    if (transactionCount == 0) {
        printf("No transactions recorded.\n");
        return;
    }

    for (int i = 0; i < transactionCount; i++) {
        printf("%d. %s: $%.2f (%s)\n", i + 1, transactions[i].type, transactions[i].amount, transactions[i].category);
    }
}

// Function to view summary report
void viewSummaryReport(Transaction transactions[], int transactionCount) {
    printf("\n=== Summary Report ===\n");
    if (transactionCount == 0) {
        printf("No transactions recorded.\n");
        return;
    }

    float totalIncome = 0.0;
    float totalExpense = 0.0;
    float incomeByCategory[3] = {0}; // Salary, Gift, Other
    float expenseByCategory[4] = {0}; // Food, Rent, Utilities, Other

    // Calculate totals
    for (int i = 0; i < transactionCount; i++) {
        if (strcmp(transactions[i].type, "Income") == 0) {
            totalIncome += transactions[i].amount;
            if (strcmp(transactions[i].category, "Salary") == 0) incomeByCategory[0] += transactions[i].amount;
            else if (strcmp(transactions[i].category, "Gift") == 0) incomeByCategory[1] += transactions[i].amount;
            else if (strcmp(transactions[i].category, "Other") == 0) incomeByCategory[2] += transactions[i].amount;
        } else if (strcmp(transactions[i].type, "Expense") == 0) {
            totalExpense += transactions[i].amount;
            if (strcmp(transactions[i].category, "Food") == 0) expenseByCategory[0] += transactions[i].amount;
            else if (strcmp(transactions[i].category, "Rent") == 0) expenseByCategory[1] += transactions[i].amount;
            else if (strcmp(transactions[i].category, "Utilities") == 0) expenseByCategory[2] += transactions[i].amount;
            else if (strcmp(transactions[i].category, "Other") == 0) expenseByCategory[3] += transactions[i].amount;
        }
    }

    // Display totals
    printf("Total Income: $%.2f\n", totalIncome);
    printf(" - Salary: $%.2f\n", incomeByCategory[0]);
    printf(" - Gift: $%.2f\n", incomeByCategory[1]);
    printf(" - Other: $%.2f\n", incomeByCategory[2]);
    printf("Total Expenses: $%.2f\n", totalExpense);
    printf(" - Food: $%.2f\n", expenseByCategory[0]);
    printf(" - Rent: $%.2f\n", expenseByCategory[1]);
    printf(" - Utilities: $%.2f\n", expenseByCategory[2]);
    printf(" - Other: $%.2f\n", expenseByCategory[3]);
}

int main() {
    float balance = 0.0; // Tracks total balance
    Transaction transactions[MAX_TRANSACTIONS]; // Array to store transactions
    int transactionCount = 0; // Number of transactions
    int choice;

    // Load transactions from file at program start
    loadTransactions(transactions, &transactionCount, &balance);

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Error: Invalid choice (must be a number)!\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addIncome(&balance, transactions, &transactionCount);
                break;
            case 2:
                addExpense(&balance, transactions, &transactionCount);
                break;
            case 3:
                viewBalance(balance);
                break;
            case 4:
                viewTransactionHistory(transactions, transactionCount);
                break;
            case 5:
                viewSummaryReport(transactions, transactionCount);
                break;
            case 6:
                saveTransactions(transactions, transactionCount);
                printf("Transactions saved. Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}