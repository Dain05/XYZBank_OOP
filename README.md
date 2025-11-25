XYZ Bank – Assignment 1

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
This project is Assignment 1 for the XYZ Bank ATM program. It is a simple C++ console application that allows a user to:
1. Check account balance
2. Deposit money
3. Withdraw money
4. Exit the program

The application uses a while loop and switch statement to control the menu. It also uses a basic Account class to store and manage the balance.

Account Class:
- Private data member:
  balance (double)

- Constructor:
  Account(double init_balance)
  If init_balance is greater than or equal to 1000.00, the balance is set to that value.
  Otherwise, the balance is set to 0 and a warning message is displayed.

- Member functions:
  deposit(double amount)
    Adds amount to the balance if amount is greater than 0.

  withdraw(double amount)
    Subtracts amount from the balance if there are enough funds.
    If amount is greater than the current balance, it displays:
    "Debit amount exceeded account balance."

  getBalance() const
    Returns the current balance.

Menu and Flow:
- The program asks the user for an initial balance and creates an Account object.
- A while loop keeps the ATM menu running until the user chooses option 4 (Exit).
- A switch statement handles each menu option:
  1 -> Display balance
  2 -> Prompt for a deposit amount and update balance
  3 -> Prompt for a withdrawal amount and try to withdraw
  4 -> Exit message

How to Compile and Run (MSYS2 UCRT64):
g++ -std=c++20 -Wall main.cpp -o atm.exe
./atm.exe

