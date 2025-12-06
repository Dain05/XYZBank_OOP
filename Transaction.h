#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <sstream>
#include <iomanip>

class Transaction {
private:
    double amount;          // money amount for this transaction
    std::string type;       // deposit, withdrawal, interest, fee, etc.
    std::string status;     // OK, FAILED, INVALID, etc.

public:
    // Parameterized constructor
    Transaction(double amt, const std::string& t, const std::string& st)
        : amount(amt), type(t), status(st) {}

    // Build a formatted string with transaction info
    std::string report() const {
        std::ostringstream ss;
        ss << "Type: " << type
           << " | Amount: $" << std::fixed << std::setprecision(2) << amount
           << " | Status: " << status;
        return ss.str();
    }
};

#endif // TRANSACTION_H
