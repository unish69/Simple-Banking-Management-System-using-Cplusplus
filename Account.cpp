// Contains account-related functions such as create, edit, deposit, and withdraw.

#include "Account.h"

// Default constructor
Account::Account()
{
    accountNumber = 0;
    name = "";
    balance = 0.0;
}

// Parameterized constructor
Account::Account(int accNo, string accName, double accBalance)
{
    accountNumber = accNo;
    name = accName;
    balance = accBalance;
}

// Return account number
int Account::getAccountNumber() const
{
    return accountNumber;
}

// Return account holder's name
string Account::getName() const
{
    return name;
}

// Return current balance
double Account::getBalance() const
{
    return balance;
}

// Change account holder's name
void Account::setName(string newName)
{
    name = newName;
}

// Change account balance
void Account::setBalance(double newBalance)
{
    balance = newBalance;
}

// Deposit money
void Account::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
    }
}

// Withdraw money
// Returns true if withdrawal is successful
// Returns false if amount is invalid or balance is insufficient
bool Account::withdraw(double amount)
{
    if (amount <= 0)
    {
        return false;
    }

    if (amount > balance)
    {
        return false;
    }

    balance -= amount;

    return true;
}