XYZ Bank – Assignment 2

Course:
Introduction to Object Oriented Programming
Lecturer: Doron Williams

Group Members:
Dain Thorpe
Shanique Wisdom
Joan Johnson-Brown
Dante Graham
Pasha Pinnock

Description:
This project is Assignment 2 and continues from Assignment 1. The goal is to expand the XYZ Bank application by using inheritance, constructors, and redefined member functions. The program now includes two derived classes: SavingsAccount and ChequingAccount, both of which inherit from the Account base class.

Class Structure:

1. Account (Base Class)
- Private data member:
  balance: double

- Constructor:
  Validates that the initial balance is greater than or equal to $1000. If not, sets balance to 0 and displays a warning message.

- Member functions:
  credit(double amount)           -- adds money to the balance
  virtual bool debit(double amt)  -- withdraws money if sufficient funds are available
  getBalance() const              -- returns the current balance

2. SavingsAccount (Inherits from Account)
- Additional data member:
  interestRate: double

- Constructor:
  Inherits balance from Account
  Takes a parameter for interestRate

- Member function:
  CalculateInterest() const
  Returns (balance * interestRate)

3. ChequingAccount (Inherits from Account)
- Additional data member:
  fee: double

- Constructor:
  Inherits balance from Account
  Takes a parameter for the transaction fee

- Redefined debit function:
  debit(double amount)
  Subtracts (amount + fee) only when the withdrawal is successful.
  If amount exceeds balance, shows an error message and does not deduct fee.

Test Program:
- Creates a SavingsAccount object
- Calculates interest and applies it to the balance
- Creates a ChequingAccount object
- Performs a successful withdrawal
- Performs a failed withdrawal (no fee should be charged)
- Displays all results in the console

Compilation Instructions (MSYS2 UCRT64):
g++ -std=c++20 -Wall main.cpp -o bank.exe
./bank.exe

Expected Output Summary:
- SavingsAccount correctly calculates interest
- ChequingAccount correctly charges fee only on successful withdrawals
- Failed withdrawals show an error and do not apply the fee
- Balances update correctly after all operations

Notes:
Assignment 2 continues from Assignment 1.
Assignment 3 will also continue from this structure.
A separate branch will be created for Assignment 3 using this updated code as the base.
