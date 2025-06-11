Personal Finance Tracker
A command-line C program designed to manage personal finances by tracking income and expenses. This beginner-friendly project demonstrates core C programming concepts including file I/O, structs, arrays, and robust input validation. Built to showcase practical programming skills for resume purposes.
Features

Add Transactions: Record income (e.g., Salary, Gift) and expenses (e.g., Food, Rent) with amounts and categories.
View Balance: Display the current balance (income minus expenses).
Transaction History: List all transactions with type, amount, and category.
Summary Report: Show total income and expenses, broken down by category.
Persistent Storage: Save transactions to transactions.txt for data persistence across sessions.
Input Validation: Handle invalid inputs (e.g., non-numeric values, negative amounts) gracefully.

Prerequisites
To run this program, you need:

Git: To clone the repository (install Git).
C Compiler:
Windows: MinGW (download).
Mac: Xcode Command Line Tools.
Linux: gcc (install via package manager, e.g., sudo apt install gcc).


Text Editor: Visual Studio Code recommended for editing and running.

Installation

Clone the Repository:
git clone https://github.com/Ishika-1608/FinanceTracker.git
cd FinanceTracker

Replace yourusername with the repository owner's GitHub username.

Install a C Compiler:

Windows:
Install MinGW and select the mingw32-gcc package.
Add MinGW’s bin folder (e.g., C:\MinGW\bin) to your system PATH:
Right-click “This PC” → Properties → Advanced system settings → Environment Variables → Edit “Path”.


Verify: gcc --version in Git Bash.


Mac:
Install Xcode Command Line Tools:xcode-select --install


Verify: gcc --version in Terminal.


Linux (Ubuntu/Debian):
Install gcc:sudo apt update
sudo apt install gcc


Verify: gcc --version.




Compile the Program:
gcc finance_tracker.c -o finance_tracker


Run the Program:

Windows: finance_tracker.exe
Mac/Linux: ./finance_tracker



Usage
Upon running, the program displays a menu:
=== Personal Finance Tracker ===
1. Add Income
2. Add Expense
3. View Balance
4. View Transaction History
5. View Summary Report
6. Exit
Enter your choice (1-6):

Example Workflow

Add Income:
Select 1, enter amount (e.g., 1000.50), choose category (e.g., 1 for Salary).
Output: Added income: $1000.50 (Salary)


Add Expense:
Select 2, enter amount (e.g., 200.25), choose category (e.g., 1 for Food).
Output: Added expense: $200.25 (Food)


View Balance:
Select 3.
Output: Current Balance: $800.25


View Transaction History:
Select 4.
Output:=== Transaction History ===
1. Income: $1000.50 (Salary)
2. Expense: $200.25 (Food)




View Summary Report:
Select 5.
Output:=== Summary Report ===
Total Income: $1000.50
 - Salary: $1000.50
 - Gift: $0.00
 - Other: $0.00
Total Expenses: $200.25
 - Food: $200.25
 - Rent: $0.00
 - Utilities: $0.00
 - Other: $0.00




Exit:
Select 6 to save transactions to transactions.txt and exit.



Notes

Input: Use numbers for menu choices, amounts (e.g., 100.50), and category selections. Invalid inputs (e.g., letters, negative amounts) prompt error messages.
Data Persistence: Transactions are saved to transactions.txt in the project folder and loaded on startup.
Transaction Limit: Supports up to 100 transactions (configurable via MAX_TRANSACTIONS).

File Structure

finance_tracker.c: Main source code implementing the finance tracker.
README.md: This documentation file.
.gitignore: Excludes generated files (e.g., transactions.txt, finance_tracker, finance_tracker.exe).
transactions.txt: Auto-generated file for storing transactions (not included in repository).

Troubleshooting

“gcc: command not found”: Install a C compiler (see Installation).
Compilation Errors: Ensure finance_tracker.c is in the folder and check for typos. Share error messages via GitHub Issues.
Program Crashes: Verify inputs are numeric and transactions.txt (if exists) is formatted correctly (e.g., Income 1000.50 Salary per line).
File Errors: Ensure the project folder has write permissions for transactions.txt.
Report issues: [https://github.com/Ishika-1608/FinanceTracker/issues]

Future Enhancements

Add transaction dates using time.h.
Support editing or deleting transactions.
Export summary reports to a separate file.

Author
Ishika Malav - A beginner C project to demonstrate skills in file I/O, structs, arrays, and input validation.

GitHub: [https://github.com/Ishika-1608/FinanceTracker]
Created: June 2025

License
This project is open-source and available under the MIT License.
