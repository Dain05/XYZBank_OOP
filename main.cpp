#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// ---------------------------------------------------------
// Group: Dain Thorpe, Shanique Wisdom,
//        Joan Johnson-Brown, Dante Graham, Pasha Pinnock
// Course: Introduction to Object Oriented Programming
// Assignment 2 - Bank Inheritance (XYZ Bank)
// ---------------------------------------------------------

// Base Account class
class Account {
private:
    double balance;   // account balance

public:
    // Constructor receives and validates the initial balance
    Account(double initialBalance) {
        if (initialBalance >= 1000.0) {
            balance = initialBalance;
        } else {
            balance = 0.0;
            cout << "Warning: Initial balance must be at least $1000.\n";
            cout << "Account balance set to $0.\n\n";
        }
    }

    // Add money to the account
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Credit amount must be positive.\n";
        }
    }

    // Withdraw money from the account
    // Returns true if the transaction was successful
    virtual bool debit(double amount) {
        if (amount <= 0) {
            cout << "Debit amount must be positive.\n";
            return false;
        }

        if (amount > balance) {
            cout << "Debit amount exceeded account balance.\n";
            return false;
        }

        balance -= amount;
        return true;
    }

    // Return the current balance
    double getBalance() const {
        return balance;
    }

    // Simple helper to display account info
    virtual void displayInfo(const string& label) const {
        cout << label << " balance: $" << balance << endl;
    }

    virtual ~Account() = default;
};

// ---------------------------------------------------------
// SavingsAccount - derived from Account
// Adds an interest rate and a function to calculate interest
// ---------------------------------------------------------
class SavingsAccount : public Account {
private:
    double interestRate;   // e.g. 0.03 for 3%

public:
    // Constructor: calls Account constructor, then sets interest rate
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance), interestRate(rate) {}

    // Return the interest earned: balance * interestRate
    double calculateInterest() const {
        return getBalance() * interestRate;
    }
};

// ---------------------------------------------------------
// ChequingAccount - derived from Account
// Adds a transaction fee and redefines debit()
// ---------------------------------------------------------
class ChequingAccount : public Account {
private:
    double transactionFee;   // fee charged per successful transaction

public:
    // Constructor: calls Account constructor, then sets fee
    ChequingAccount(double initialBalance, double fee)
        : Account(initialBalance), transactionFee(fee) {}

    // Redefine debit so that it charges a fee ONLY when
    // the withdrawal is successful
    bool debit(double amount) override {
        // First try to withdraw the requested amount
        bool success = Account::debit(amount);

        if (success) {
            // Only charge fee when money was actually withdrawn
            bool feeSuccess = Account::debit(transactionFee);

            if (feeSuccess) {
                cout << "Transaction fee of $" << transactionFee
                     << " charged.\n";
            } else {
                cout << "Warning: Could not deduct transaction fee.\n";
            }
        }

        return success;
    }
};

// ---------------------------------------------------------
// Test program for Assignment 2
// ---------------------------------------------------------
int main() {
    cout << "=== XYZ Bank - Assignment 2 Test Program ===\n\n";

    // Create a SavingsAccount with 3% interest
    SavingsAccount savings(5000.0, 0.03);   // 3% = 0.03

    // Create a ChequingAccount with a $50 transaction fee
    ChequingAccount chequing(3000.0, 50.0);

    cout << "Initial balances:\n";
    savings.displayInfo("Savings");
    chequing.displayInfo("Chequing");
    cout << endl;

    // ---- Test SavingsAccount interest calculation ----
    double interest = savings.calculateInterest();
    cout << "Calculated interest for SavingsAccount at 3%: $"
         << interest << endl;

    cout << "Adding interest to SavingsAccount balance...\n";
    savings.credit(interest);

    cout << "Savings balance after adding interest:\n";
    savings.displayInfo("Savings");
    cout << endl;

    // ---- Test ChequingAccount withdrawal with enough funds ----
    cout << "Attempting to withdraw $500 from ChequingAccount...\n";
    chequing.debit(500.0);

    cout << "Chequing balance after withdrawal and fee:\n";
    chequing.displayInfo("Chequing");
    cout << endl;

    // ---- Test ChequingAccount withdrawal with too much money ----
    cout << "Attempting to withdraw $10000 from ChequingAccount...\n";
    chequing.debit(10000.0);

    cout << "Chequing balance after failed withdrawal:\n";
    chequing.displayInfo("Chequing");
    cout << endl;

    cout << "=== End of tests ===\n";
    return 0;
}
