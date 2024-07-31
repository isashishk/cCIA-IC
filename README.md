# C CIA-I Case Study Implementation

# Finance Tracker

A simple C program to manage your personal finances by tracking transactions, calculating balance, and generating reports.

## Features
- Add income and expense transactions
- Calculate current balance
- Generate a report of all transactions
- Display all transactions
- Save and load transaction data to/from a file

## Requirements
- C compiler (e.g., GCC)

## How to Use

### Compile the Program
```sh
gcc finance_tracker.c -o finance_tracker
```

### Run the Program
```sh
finance_tracker.exe
```

### Menu Options
1. **Add Transaction**: Enter transaction details in the format `date(YYYY-MM-DD) type(income/expense) category(e.g., food, rent) amount`.
2. **Calculate Balance**: Display the current balance by summing all income and subtracting all expenses.
3. **Generate Report**: Create a `report.txt` file with all transaction details.
4. **Display All Transactions**: Show all transactions on the screen.
5. **Exit**: Save all transactions to `transactions.txt` and exit the program.

## Code Structure

- **Transaction Struct**: Holds transaction details (`date`, `type`, `category`, `amount`) and a pointer to the next transaction.
- **create_transaction**: Creates a new transaction from user input.
- **add_transaction**: Adds a new transaction to the list.
- **calculate_balance**: Computes the current balance.
- **generate_report**: Writes all transactions to a `report.txt` file.
- **save_data**: Saves all transactions to `transactions.txt`.
- **load_data**: Loads transactions from `transactions.txt`.
- **display_transactions**: Displays all transactions on the console.
- **display_menu**: Shows the main menu options.

## Sample Transaction Format
```plaintext
2023-07-31 income salary 3000.00
2023-07-31 expense food 50.00
```

## Example Output
```plaintext
Finance Tracker Menu:
1. Add Transaction
2. Calculate Balance
3. Generate Report
4. Display All Transactions
5. Exit
Enter your choice: 1
Enter transaction (date(YYYY-MM-DD) type(income/expense) category(e.g., food, rent) amount):
2023-07-31 income salary 3000.00

Finance Tracker Menu:
1. Add Transaction
2. Calculate Balance
3. Generate Report
4. Display All Transactions
5. Exit
Enter your choice: 2

Balance: 3000.00
```

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
