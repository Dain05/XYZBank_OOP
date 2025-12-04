# XYZ Bank – Assignment 3

**Module:** Introduction to Object Oriented Programming  
**Lecturer:** Doron Williams  

---

## Group Members
- Joan Johnson-Brown  
- Dain Thorpe  
- Shanique Wisdom  
- Dante Graham  
- Pasha Pinnock  

---

## Project Description

This program extends the XYZ Bank application to record and display a log of all transactions performed on an account.

### Key Features
- **Transaction class**  
  Stores the transaction amount, type, and status. Includes a `report()` function that formats transaction details.

- **Account class**  
  Now contains a `std::vector<Transaction>` log to store all transaction records.  
  Includes methods to add new transactions and generate reports.

- **SavingsAccount and ChequingAccount**  
  Both inherit from the `Account` class and implement their specific behaviours (interest, transaction fees, etc.).

- **Reporting**  
  Each account produces a formatted transaction report.  
  The full report is saved to `transactions.txt` using file I/O.

- **Exception Handling**  
  Uses `try/catch` blocks to safely handle invalid input, file I/O issues, and general runtime errors.

---

## Files Included
- **Transaction.h** – Transaction class and `report()` formatting.  
- **Account.h** – Account base class, SavingsAccount and ChequingAccount classes, and transaction log.  
- **main.cpp** – Test code, file saving, and exception handling.

---

## How to Compile and Run (MSYS2 / g++)
From inside the **Assignment3** folder:

```bash
g++ -std=c++20 main.cpp -o bank.exe
./bank.exe
