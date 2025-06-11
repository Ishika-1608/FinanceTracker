# Personal Finance Tracker

A command-line C program to track personal income and expenses, with persistent storage and summary reporting.

## Features
- Add income and expense transactions with categories (e.g., Salary, Food).
- View current balance and transaction history.
- Generate a summary report of total income and expenses by category.
- Save transactions to a file (`transactions.txt`) for persistence across sessions.

## How to Run
1. **Install a C Compiler**:
   - Windows: Install MinGW and add to PATH.
   - Mac: Install Xcode Command Line Tools (`xcode-select --install`).
   - Linux: Install gcc (`sudo apt install gcc`).
2. **Compile the Program**:
   ```bash
   gcc finance_tracker.c -o finance_tracker