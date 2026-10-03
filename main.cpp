// Displays the menu and handles user choices.

#include <iostream>
#include "Bank.h"

using namespace std;

int main()
{
    // Create Bank object
    // Existing accounts are automatically loaded
    Bank bank;

    int choice;

    do
    {
        cout << "\n\n";
        cout << "========================================\n";
        cout << "          SIMPLE BANKING SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Create Account\n";
        cout << "2. Display Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Search Account\n";
        cout << "6. Edit Account\n";
        cout << "7. Delete Account\n";
        cout << "8. Display All Accounts\n";
        cout << "9. Exit\n";

        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                bank.createAccount();
                break;

            case 2:
                bank.displayAccount();
                break;

            case 3:
                bank.depositMoney();
                break;

            case 4:
                bank.withdrawMoney();
                break;

            case 5:
                bank.searchAccount();
                break;

            case 6:
                bank.editAccount();
                break;

            case 7:
                bank.deleteAccount();
                break;

            case 8:
                bank.displayAllAccounts();
                break;

            case 9:
                cout << "\nThank you for using the Banking System!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}