// Contains account-related functions such as create, edit, deposit, and withdraw.

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
using namespace std;

// Account class stores information about one bank account
class Account
{
private:
    int accountNumber;
    string name;
    double balance;

public:
    // Default constructor
    Account();

    // Parameterized constructor
    Account(int accNo, string accName, double accBalance);

    // Getter functions
    int getAccountNumber() const;
    string getName() const;
    double getBalance() const;

    // Setter functions
    void setName(string newName);
    void setBalance(double newBalance);

    // Deposit money into the account
    void deposit(double amount);

    // Withdraw money from the account
    bool withdraw(double amount);
};

#endif