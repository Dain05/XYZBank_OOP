// XYZ Bank – Assignment 3
// Group Members:
//   Joan Johnson-Brown
//   Dain Thorpe
//   Shanique Wisdom
//   Dante Graham
//   Pasha Pinnock
// Lecturer: Doron Williams

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Account.h"

// Helper function – write report string to a file
bool saveReportToFile(const std::string& filename,
                      const std::string& content) {
    std::ofstream outFile(filename);

    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
        return true;
    }

    return false;
}

int main() {
    try {
        std::cout << "--- XYZ Bank: Transaction Logger ---\n\n";

        // Create test accounts
        SavingsAccount  savings (5000.0, 0.06);   // 6% per year
        ChequingAccount chequing(3000.0, 50.0);   // $50 fee per transaction

        // Display initial balances
        savings.display("Dain Thorpe - Savings");
        chequing.display("Dain Thorpe - Chequing");
        std::cout << '\n';

        // === Test new functionality in main() ===

        // Savings account activity
        savings.deposit(1000.0);
        savings.withdraw(500.0);
        savings.applyMonthlyInterest();

        // Chequing account activity
        chequing.deposit(2000.0);
        chequing.withdraw(1500.0);
        chequing.withdraw(4000.0);   // should fail (insufficient incl. fee)

        // Show transaction history on screen
        std::cout << "\n--- Savings Transactions ---\n";
        std::cout << savings.report() << '\n';

        std::cout << "\n--- Chequing Transactions ---\n";
        std::cout << chequing.report() << '\n';

        // === Save full report to file ===
        std::cout << "\nSaving transactions...\n";

        std::string fileReport;
        fileReport += savings.getTransactionsReport("Dain Thorpe - Savings");
        fileReport += chequing.getTransactionsReport("Dain Thorpe - Chequing");

        // You can change the path if needed (e.g. C:\\transactions.txt on Windows)
        const std::string filename = "transactions.txt";

        if (saveReportToFile(filename, fileReport)) {
            std::cout << "Transactions successfully saved to "
                      << filename << '\n';
        } else {
            throw std::runtime_error("Failed to save transactions report file");
        }
    }
    // === Defensive programming: catch any thrown exceptions ===
    catch (const std::invalid_argument& ex) {
        std::cerr << "\nRUNTIME ERROR (INVALID ARGUMENT): "
                  << ex.what() << std::endl;
    }
    catch (const std::runtime_error& ex) {
        std::cerr << "\nRUNTIME ERROR (FILE I/O): "
                  << ex.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "\nRUNTIME ERROR: "
                  << ex.what() << std::endl;
    }

    return 0;
}
