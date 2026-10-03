// Defines the banking-system functions.

#ifndef BANK_H
#define BANK_H

#include "Account.h"
#include <vector>
#include <string>
using namespace std;

// Bank class manages all bank accounts
class Bank
{
private:
    vector<Account> accounts;

    // File used to permanently store account information
    string fileName;

    // Load accounts from file
    void loadFromFile();

    // Save all accounts to file
    void saveToFile();

public:
    // Constructor
    Bank();

    // Create a new account
    void createAccount();

    // Display a particular account
    void displayAccount();

    // Deposit money
    void depositMoney();

    // Withdraw money
    void withdrawMoney();

    // Search for an account
    void searchAccount();

    // Edit account information
    void editAccount();

    // Delete an account
    void deleteAccount();

    // Display all accounts
    void displayAllAccounts();
};

#endif