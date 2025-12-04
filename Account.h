#ifndef ACCOUNT_H
#define ACCOUNT_H

// XYZ Bank – Assignment 3
// Group Members:
//   Joan Johnson-Brown
//   Dain Thorpe
//   Shanique Wisdom
//   Dante Graham
//   Pasha Pinnock
// Lecturer: Doron Williams

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iomanip>
#include "Transaction.h"

// Base Account class – holds balance and transaction log
class Account {
protected:
    double balance;
    std::vector<Transaction> log;   // vector used to store all transactions

public:
    // Parameterized constructor
    explicit Account(double initialBalance = 0.0)
        : balance(initialBalance) {
        if (initialBalance < 0.0) {
            throw std::invalid_argument("Initial balance cannot be negative.");
        }
    }

    virtual ~Account() = default;

    double getBalance() const {
        return balance;
    }

    // Deposit money and record the transaction
    virtual void deposit(double amount) {
        if (amount <= 0.0) {
            logTransaction(amount, "Deposit", "INVALID AMOUNT");
            throw std::invalid_argument("Deposit amount must be positive.");
        }

        balance += amount;
        logTransaction(amount, "Deposit", "OK");
    }

    // Withdraw money and record the transaction
    virtual bool withdraw(double amount) {
        if (amount <= 0.0) {
            logTransaction(amount, "Withdrawal", "INVALID AMOUNT");
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }

        if (amount > balance) {
            logTransaction(amount, "Withdrawal (FAILED)", "INSUFFICIENT FUNDS");
            return false;
        }

        balance -= amount;
        logTransaction(amount, "Withdrawal", "OK");
        return true;
    }

    // Text summary of all transactions for console display
    std::string report() const {
        std::ostringstream ss;

        if (log.empty()) {
            ss << "No transactions recorded.\n";
            return ss.str();
        }

        for (const auto& tx : log) {
            ss << tx.report() << '\n';
        }

        ss << "Current Balance: $" << std::fixed << std::setprecision(2)
           << balance << '\n';

        return ss.str();
    }

    // Text summary for saving to file (includes account label)
    std::string getTransactionsReport(const std::string& accountLabel) const {
        std::ostringstream ss;

        ss << "=== Transaction Report for " << accountLabel << " ===\n";

        if (log.empty()) {
            ss << "No transactions recorded.\n\n";
            return ss.str();
        }

        for (const auto& tx : log) {
            ss << tx.report() << '\n';
        }

        ss << "Ending Balance: $" << std::fixed << std::setprecision(2)
           << balance << "\n\n";

        return ss.str();
    }

    // Simple display method for starting account info
    void display(const std::string& accountLabel) const {
        std::cout << accountLabel
                  << " | Balance: $"
                  << std::fixed << std::setprecision(2)
                  << balance << std::endl;
    }

protected:
    // Internal helper – add a transaction to the log
    void logTransaction(double amount,
                        const std::string& type,
                        const std::string& status) {
        log.emplace_back(amount, type, status);
    }
};

// SavingsAccount adds interest on the balance
class SavingsAccount : public Account {
private:
    double annualInterestRate;   // e.g. 0.06 for 6%

public:
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance), annualInterestRate(rate) {
        if (annualInterestRate < 0.0) {
            throw std::invalid_argument("Interest rate cannot be negative.");
        }
    }

    // Apply one month of interest and log it as a transaction
    void applyMonthlyInterest() {
        double monthlyRate = annualInterestRate / 12.0;
        double interest = balance * monthlyRate;

        if (interest != 0.0) {
            balance += interest;
            logTransaction(interest, "Monthly Interest", "OK");
        }
    }
};

// ChequingAccount charges a fee per transaction
class ChequingAccount : public Account {
private:
    double transactionFee;

public:
    ChequingAccount(double initialBalance, double fee)
        : Account(initialBalance), transactionFee(fee) {
        if (transactionFee < 0.0) {
            throw std::invalid_argument("Transaction fee cannot be negative.");
        }
    }

    void deposit(double amount) override {
        if (amount <= 0.0) {
            logTransaction(amount, "Deposit", "INVALID AMOUNT");
            throw std::invalid_argument("Deposit amount must be positive.");
        }

        balance += amount;
        logTransaction(amount, "Deposit", "OK");
    }

    bool withdraw(double amount) override {
        if (amount <= 0.0) {
            logTransaction(amount, "Withdrawal", "INVALID AMOUNT");
            throw std::invalid_argument("Withdrawal amount must be positive.");
        }

        double total = amount + transactionFee;

        if (total > balance) {
            logTransaction(amount, "Withdrawal (FAILED)", "INSUFFICIENT (incl. fee)");
            // log the fee attempt as well to show what happened
            logTransaction(transactionFee, "Transaction Fee", "NOT CHARGED");
            return false;
        }

        balance -= total;
        logTransaction(amount, "Withdrawal", "OK");
        logTransaction(transactionFee, "Transaction Fee", "OK");
        return true;
    }
};

#endif // ACCOUNT_H
