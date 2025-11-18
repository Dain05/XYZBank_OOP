\# XYZ Bank – Assignment 2



\## Course

Introduction to Object Oriented Programming  



\## Group Members

\- Dain Thorpe  

\- Shanique Wisdom  

\- Joan Johnson-Brown  

\- Dante Graham  

\- Pasha Pinnock  



\## Description

This project is a continuation of the XYZ Bank application from Assignment 1.  

It implements an inheritance hierarchy with:



\- `Account` (base class)  

\- `SavingsAccount` (inherits from `Account`)  

\- `ChequingAccount` (inherits from `Account`)  



\### Account

\- Stores the account `balance` as a private data member.  

\- Constructor validates the initial balance (must be ≥ 1000, otherwise sets balance to 0 and prints a warning).  

\- `credit(double amount)` – adds money to the balance.  

\- `virtual bool debit(double amount)` – withdraws money if there are enough funds.  

\- `double getBalance() const` – returns the current balance.  

\- `virtual void displayInfo(const std::string\& label) const` – prints the balance with a label.



\### SavingsAccount

\- Inherits all `Account` functionality.  

\- Has an additional private data member `interestRate`.  

\- Constructor takes `initialBalance` and `interestRate` and passes the balance to the `Account` constructor.  

\- `double calculateInterest() const` – returns `getBalance() \* interestRate`.



\### ChequingAccount

\- Inherits from `Account`.  

\- Has a private data member `transactionFee`.  

\- Constructor takes `initialBalance` and `transactionFee` and passes the balance to the `Account` constructor.  

\- Redefines `debit(double amount)` so that it:

&nbsp; - Calls `Account::debit(amount)` to attempt the withdrawal.  

&nbsp; - If the withdrawal is successful, charges the transaction fee by calling `Account::debit(transactionFee)`.  

&nbsp; - Only charges the fee when the withdrawal succeeds.



\## How to Compile and Run



From the \*\*MSYS2 UCRT64\*\* terminal:



```bash

cd /c/Users/Anonymous/Documents/XYZBank\_OOP

g++ -std=c++20 -Wall main.cpp -o bank.exe

./bank.exe



