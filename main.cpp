// Intro to Object Oriented Programming
// Module 1 - Assignment 1
// XYZ Bank ATM Program
// Group Members:
//   Dain Thorpe
//   Shanique Wisdom
//   Joan Johnson-Brown
//   Dante Graham
//   Pasha Pinnock
// Lecturer: Doron Williams

#include <iostream>
using namespace std;

// Account class represents a customer's bank account
class Account {
private:
    double balance;   // account balance (data member)

public:
    // Constructor receives and initializes the initial balance
    Account(double init_balance) {
        if (init_balance >= 1000.0) {
            balance = init_balance;
        } else {
            cout << "Invalid initial balance. Account set to $0.\n";
            balance = 0.0;
        }
    }

    // Optional: setBalance if needed later
    void setBalance(double newBalance) {
        if (newBalance >= 0) {
            balance = newBalance;
        }
    }

    // GetBalance() returns the account's current balance
    double getBalance() const {
        return balance;
    }

    // Deposit() adds an amount to the current balance and returns new balance
    double deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be greater than 0.\n";
            return balance;
        }

        balance += amount;
        cout << "Deposit successful.\n";
        return balance;
    }

    // Withdraw() debits money and makes sure amount does not exceed balance
    // Returns true if withdrawal is successful, false otherwise
    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be greater than 0.\n";
            return false;
        }

        if (amount > balance) {
            cout << "Debit amount exceeded account balance.\n";
            return false;
        }

        balance -= amount;
        cout << "Withdrawal successful.\n";
        return true;
    }
};

int main() {
    cout << "===== XYZ Bank ATM =====\n\n";

    // Ask user for initial balance and create the Account object
    double initialBalance;
    cout << "Enter your initial balance: ";
    cin >> initialBalance;

    Account account(initialBalance);

    int choice = 0;

    // while loop keeps the program running until user chooses to exit
    while (choice != 4) {
        cout << "\n===== XYZ Bank ATM =====\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        cout << endl;

        switch (choice) {
        case 1: {
            // Check balance
            cout << "Current balance: $" << account.getBalance() << endl;
            break;
        }
        case 2: {
            // Deposit money
            double amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;

            account.deposit(amount);
            cout << "New balance: $" << account.getBalance() << endl;
            break;
        }
        case 3: {
            // Withdraw money
            double amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            bool success = account.withdraw(amount);
            if (success) {
                cout << "New balance: $" << account.getBalance() << endl;
            }
            break;
        }
        case 4:
            // Exit program
            cout << "Thank you for using XYZ Bank ATM.\n";
            break;
        default:
            // Handle wrong menu choice
            cout << "Invalid option. Please choose 1 - 4.\n";
        }
    }

    return 0;
}

