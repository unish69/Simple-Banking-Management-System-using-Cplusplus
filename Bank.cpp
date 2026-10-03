// Handles searching, displaying, deleting, and file operations.

#include "Bank.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;


// Constructor
Bank::Bank()
{
    // Name of the file used to store accounts
    fileName = "accounts.txt";

    // Load existing accounts when program starts
    loadFromFile();
}


// --------------------------------------------------
// LOAD ACCOUNTS FROM FILE
// --------------------------------------------------

void Bank::loadFromFile()
{
    ifstream file(fileName);

    // If file doesn't exist, there are no accounts yet
    if (!file)
    {
        return;
    }

    string line;

    while (getline(file, line))
    {
        if (line.empty())
        {
            continue;
        }

        stringstream ss(line);

        string accountNumberString;
        string name;
        string balanceString;

        // File format:
        // accountNumber|name|balance

        getline(ss, accountNumberString, '|');
        getline(ss, name, '|');
        getline(ss, balanceString, '|');

        int accountNumber = stoi(accountNumberString);
        double balance = stod(balanceString);

        Account acc(accountNumber, name, balance);

        accounts.push_back(acc);
    }

    file.close();
}


// --------------------------------------------------
// SAVE ACCOUNTS TO FILE
// --------------------------------------------------

void Bank::saveToFile()
{
    // ios::trunc removes old data and writes
    // the current account information again
    ofstream file(fileName, ios::trunc);

    for (const Account& acc : accounts)
    {
        file << acc.getAccountNumber() << "|"
             << acc.getName() << "|"
             << acc.getBalance() << endl;
    }

    file.close();
}


// --------------------------------------------------
// CREATE ACCOUNT
// --------------------------------------------------

void Bank::createAccount()
{
    int accountNumber;
    string name;
    double balance;

    cout << "\n========== CREATE ACCOUNT ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    // Check whether account number already exists
    for (const Account& acc : accounts)
    {
        if (acc.getAccountNumber() == accountNumber)
        {
            cout << "Account number already exists!\n";
            return;
        }
    }

    cin.ignore();

    cout << "Enter Account Holder Name: ";
    getline(cin, name);

    cout << "Enter Initial Balance: ";
    cin >> balance;

    if (balance < 0)
    {
        cout << "Balance cannot be negative!\n";
        return;
    }

    Account newAccount(accountNumber, name, balance);

    accounts.push_back(newAccount);

    // Save changes permanently
    saveToFile();

    cout << "\nAccount created successfully!\n";
}


// --------------------------------------------------
// DISPLAY ONE ACCOUNT
// --------------------------------------------------

void Bank::displayAccount()
{
    int accountNumber;

    cout << "\n========== DISPLAY ACCOUNT ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (const Account& acc : accounts)
    {
        if (acc.getAccountNumber() == accountNumber)
        {
            cout << "\nAccount Number : "
                 << acc.getAccountNumber() << endl;

            cout << "Account Holder : "
                 << acc.getName() << endl;

            cout << "Balance        : $"
                 << fixed << setprecision(2)
                 << acc.getBalance() << endl;

            return;
        }
    }

    cout << "Account not found!\n";
}


// --------------------------------------------------
// SEARCH ACCOUNT
// --------------------------------------------------

void Bank::searchAccount()
{
    int accountNumber;

    cout << "\n========== SEARCH ACCOUNT ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (const Account& acc : accounts)
    {
        if (acc.getAccountNumber() == accountNumber)
        {
            cout << "\nAccount Found!\n";

            cout << "Account Number : "
                 << acc.getAccountNumber() << endl;

            cout << "Account Holder : "
                 << acc.getName() << endl;

            cout << "Balance        : $"
                 << fixed << setprecision(2)
                 << acc.getBalance() << endl;

            return;
        }
    }

    cout << "Account not found!\n";
}


// --------------------------------------------------
// DEPOSIT MONEY
// --------------------------------------------------

void Bank::depositMoney()
{
    int accountNumber;
    double amount;

    cout << "\n========== DEPOSIT MONEY ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (Account& acc : accounts)
    {
        if (acc.getAccountNumber() == accountNumber)
        {
            cout << "Current Balance: $"
                 << fixed << setprecision(2)
                 << acc.getBalance() << endl;

            cout << "Enter Amount to Deposit: ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "Invalid amount!\n";
                return;
            }

            acc.deposit(amount);

            // Save updated balance
            saveToFile();

            cout << "\nDeposit successful!\n";

            cout << "New Balance: $"
                 << fixed << setprecision(2)
                 << acc.getBalance() << endl;

            return;
        }
    }

    cout << "Account not found!\n";
}


// --------------------------------------------------
// WITHDRAW MONEY
// --------------------------------------------------

void Bank::withdrawMoney()
{
    int accountNumber;
    double amount;

    cout << "\n========== WITHDRAW MONEY ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (Account& acc : accounts)
    {
        if (acc.getAccountNumber() == accountNumber)
        {
            cout << "Current Balance: $"
                 << fixed << setprecision(2)
                 << acc.getBalance() << endl;

            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            if (amount <= 0)
            {
                cout << "Invalid amount!\n";
                return;
            }

            if (amount > acc.getBalance())
            {
                cout << "Insufficient balance!\n";
                return;
            }

            acc.withdraw(amount);

            // Save updated balance
            saveToFile();

            cout << "\nWithdrawal successful!\n";

            cout << "Remaining Balance: $"
                 << fixed << setprecision(2)
                 << acc.getBalance() << endl;

            return;
        }
    }

    cout << "Account not found!\n";
}


// --------------------------------------------------
// EDIT ACCOUNT
// --------------------------------------------------

void Bank::editAccount()
{
    int accountNumber;

    cout << "\n========== EDIT ACCOUNT ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (Account& acc : accounts)
    {
        if (acc.getAccountNumber() == accountNumber)
        {
            cout << "\nCurrent Name: "
                 << acc.getName() << endl;

            cin.ignore();

            string newName;

            cout << "Enter New Name: ";
            getline(cin, newName);

            acc.setName(newName);

            // Save changes
            saveToFile();

            cout << "\nAccount updated successfully!\n";

            return;
        }
    }

    cout << "Account not found!\n";
}


// --------------------------------------------------
// DELETE ACCOUNT
// --------------------------------------------------

void Bank::deleteAccount()
{
    int accountNumber;

    cout << "\n========== DELETE ACCOUNT ==========\n";

    cout << "Enter Account Number: ";
    cin >> accountNumber;

    for (auto it = accounts.begin(); it != accounts.end(); ++it)
    {
        if (it->getAccountNumber() == accountNumber)
        {
            accounts.erase(it);

            // Save remaining accounts
            saveToFile();

            cout << "\nAccount deleted successfully!\n";

            return;
        }
    }

    cout << "Account not found!\n";
}


// --------------------------------------------------
// DISPLAY ALL ACCOUNTS
// --------------------------------------------------

void Bank::displayAllAccounts()
{
    cout << "\n========== ALL ACCOUNTS ==========\n";

    if (accounts.empty())
    {
        cout << "No accounts found.\n";
        return;
    }

    cout << left
         << setw(15) << "Account No."
         << setw(25) << "Name"
         << setw(15) << "Balance"
         << endl;

    cout << "-------------------------------------------------------\n";

    for (const Account& acc : accounts)
    {
        cout << left
             << setw(15) << acc.getAccountNumber()
             << setw(25) << acc.getName()
             << "$" << fixed << setprecision(2)
             << acc.getBalance()
             << endl;
    }
}