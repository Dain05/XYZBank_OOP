# XYZ Bank – Assignment 3

Module: Introduction to Object Oriented Programming  
Lecturer: Doron Williams  

## Group Members

- Joan Johnson-Brown  
- Dain Thorpe  
- Shanique Wisdom  
- Dante Graham  
- Pasha Pinnock  

## Project Description

This program extends the XYZ Bank application to keep a log of all
transactions done on an account.

- A **Transaction** class stores the amount, type, and status.
- The **Account** class now has a `std::vector<Transaction>` log.
- **SavingsAccount** and **ChequingAccount** inherit from `Account`.
- The new `report()` functions build formatted strings that show the
  transaction history.
- The main file tests the new behaviour and saves the full report
  to `transactions.txt`.

## Files

- `Transaction.h` – Transaction class and `report()` function.  
- `Account.h` – Account, SavingsAccount and ChequingAccount classes,
  transaction log, and report helpers.  
- `main.cpp` – Test code, file I/O, and exception handling.  

## How to Compile and Run (MSYS2 / g++)

From the `Assignment3` folder:

```bash
g++ -std=c++20 main.cpp -o bank.exe
./bank.exe
