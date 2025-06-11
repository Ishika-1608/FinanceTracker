💰 Personal Finance Tracker

Welcome to the Personal Finance Tracker, a sleek command-line C program designed to help you manage your money with ease! 📊 Built from scratch as a beginner-friendly project, this tool showcases core C programming skills like file I/O, structs, arrays, and robust input handling. Perfect for tracking income and expenses, it’s a resume-worthy project that demonstrates practical coding prowess! 🚀

🌟 Features

📈 Add Transactions: Log income (e.g., Salary, Gift) and expenses (e.g., Food, Rent) with amounts and categories.
💸 View Balance: Check your current balance (income minus expenses) at a glance.
📜 Transaction History: Review all transactions with type, amount, and category.
📊 Summary Report: Get detailed insights with total income and expenses, broken down by category.
💾 Persistent Storage: Save transactions to transactions.txt to keep your data safe across sessions.
🛡️ Input Validation: Handles pesky invalid inputs (like non-numeric values or negative amounts) with clear error messages.


🛠️ Prerequisites

To dive into this project, you’ll need:

Git: To clone the repository (install Git). 🗂️
C Compiler:
Windows: MinGW (download).
Mac: Xcode Command Line Tools.
Linux: gcc (e.g., sudo apt install gcc).


Text Editor: Visual Studio Code is recommended for coding and running. ✍️


🚀 Installation
Get up and running in just a few steps!

Clone the Repository:
git clone https://github.com/Ishika-1608/FinanceTracker.git
cd FinanceTracker


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




🎮 Usage
Launch the program and interact with an intuitive menu:
=== Personal Finance Tracker ===
1. Add Income
2. Add Expense
3. View Balance
4. View Transaction History
5. View Summary Report
6. Exit
Enter your choice (1-6):

Example Workflow

Add Income 💵:

Select 1, enter 1000.50, choose category 1 (Salary).
Output: Added income: $1000.50 (Salary)


Add Expense 🛒:

Select 2, enter 200.25, choose category 1 (Food).
Output: Added expense: $200.25 (Food)


View Balance ⚖️:

Select 3.
Output: Current Balance: $800.25


View Transaction History 📜:

Select 4.
Output:=== Transaction History ===
1. Income: $1000.50 (Salary)
2. Expense: $200.25 (Food)




View Summary Report 📊:

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




Exit 🚪:

Select 6 to save transactions to transactions.txt and exit.



Key Notes

Input: Enter numbers only (e.g., 100.50 for amounts, 1 for categories). Invalid inputs trigger helpful error messages.
Data Persistence: Transactions are saved to transactions.txt and loaded on startup.
Transaction Limit: Supports up to 100 transactions (adjustable via MAX_TRANSACTIONS).


📂 File Structure

finance_tracker.c: The heart of the project, containing all C code.
README.md: This stylish documentation.
.gitignore: Keeps generated files (e.g., transactions.txt, finance_tracker, finance_tracker.exe) out of the repository.
transactions.txt: Auto-generated file for transaction data (not tracked in Git).


🐞 Troubleshooting

“gcc: command not found”: Install a C compiler (see Installation).
Compilation Errors: Ensure finance_tracker.c is present and error-free. Share errors via GitHub Issues.
Program Crashes: Check that inputs are numeric and transactions.txt (if present) follows the format type amount category (e.g., Income 1000.50 Salary).
File Errors: Verify write permissions for the project folder.
Need Help? File an issue: [https://github.com/Ishika-1608/FinanceTracker/issues]


🔮 Future Enhancements

🕒 Add transaction timestamps using time.h.
✂️ Support editing or deleting transactions.
📄 Export summary reports to a separate file.


👩‍💻 Author
Ishika Malav 
A beginner-friendly C project showcasing skills in file I/O, structs, arrays, and robust error handling.  

GitHub: https://github.com/Ishika-1608/FinanceTracker  
Created: June 2025


📜 License
This project is open-source under the MIT License. Feel free to use, modify, and share!
