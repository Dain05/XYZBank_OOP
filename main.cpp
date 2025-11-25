#include <iostream>
using namespace std;

// Base class: Account
class Account {
protected:
    double balance;   // current account balance

public:
    // Constructor – validates initial balance (must be >= 1000)
    Account(double init_balance) {
        if (init_balance >= 1000.0) {
            balance = init_balance;
        } else {
            balance = 0.0;
            cout << "[Warning] Initial balance must be at least $1000.00. "
                 << "Setting balance to 0.\n";
        }
    }

    // Credit – add money to the account
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "[Error] Credit amount must be positive.\n";
        }
    }

    // Debit – withdraw money if there is enough balance
    // Marked virtual so derived classes can override it
    virtual bool debit(double amount) {
        if (amount <= 0) {
            cout << "[Error] Debit amount must be positive.\n";
            return false;
        }

        if (amount > balance) {
            cout << "[Error] Debit amount exceeded account balance.\n";
            return false;
        }

        balance -= amount;
        return true;
    }

    // GetBalance – returns current balance
    double getBalance() const {
        return balance;
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate;   // interest rate as a percentage (e.g. 4.0 for 4%)

public:
    // Constructor inherits from Account and also accepts interest rate
    SavingsAccount(double init_balance, double ratePercent)
        : Account(init_balance), interestRate(ratePercent) {}

    // CalculateInterest – returns interest earned (balance * rate%)
    double calculateInterest() const {
        double rate = interestRate / 100.0;   // convert percent to decimal
        return balance * rate;
    }
};

// Derived class: ChequingAccount
class ChequingAccount : public Account {
private:
    double transactionFee;   // fee charged per successful debit

public:
    // Constructor inherits from Account and also accepts fee
    ChequingAccount(double init_balance, double fee)
        : Account(init_balance), transactionFee(fee) {}

    // Redefined debit – subtract fee only if withdrawal is successful
    bool debit(double amount) override {
        // Try the normal debit logic from Account
        if (Account::debit(amount)) {
            // Only charge fee if transaction was successful
            if (transactionFee > 0) {
                if (transactionFee <= balance) {
                    balance -= transactionFee;
                    cout << "[Info] Transaction fee of $" << transactionFee
                         << " was deducted.\n";
                } else {
                    cout << "[Warning] Fee could not be deducted "
                         << "(insufficient balance for fee).\n";
                }
            }
            return true;
        }

        // If base debit failed, no fee should be charged
        return false;
    }
};

int main() {
    cout << "=== XYZ Bank - Assignment 2 Test Program ===\n\n";

    // 1. Create a SavingsAccount object
    cout << "Creating SavingsAccount with $5000 balance and 4% interest rate...\n";
    SavingsAccount savings(5000.0, 4.0);
    cout << "SavingsAccount starting balance: $" << savings.getBalance() << "\n";

    // 2. Calculate interest and add it to the savings balance
    double interest = savings.calculateInterest();
    cout << "Calculated interest: $" << interest << "\n";
    savings.credit(interest);
    cout << "SavingsAccount balance after interest credited: $"
         << savings.getBalance() << "\n\n";

    // 3. Create a ChequingAccount object
    cout << "Creating ChequingAccount with $3000 balance and $50 fee...\n";
    ChequingAccount chequing(3000.0, 50.0);
    cout << "ChequingAccount starting balance: $" << chequing.getBalance() << "\n";

    // 4. Perform a successful withdrawal and show that the fee is charged
    cout << "\nAttempting to withdraw $500 from ChequingAccount...\n";
    chequing.debit(500.0);
    cout << "ChequingAccount balance after withdrawal and fee: $"
         << chequing.getBalance() << "\n";

    // 5. Attempt a withdrawal that should fail (no fee should be charged)
    cout << "\nAttempting to withdraw $5000 from ChequingAccount "
         << "(expected to fail)...\n";
    chequing.debit(5000.0);
    cout << "ChequingAccount balance after failed withdrawal (no fee charged): $"
         << chequing.getBalance() << "\n";

    cout << "\n=== End of test program ===\n";
    return 0;
}