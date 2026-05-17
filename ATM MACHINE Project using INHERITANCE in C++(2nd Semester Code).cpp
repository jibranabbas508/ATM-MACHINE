#include <iostream>
using namespace std;

//  BASE CLASS 

class BankAccount
{
protected:
    string name;
    double accountNumber;
    double balance;

public:
    // Create Account
    void createAccount()
    {
        cout << "Enter Account Holder Name: ";
        cin >> name;

        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    // Deposit Money
    void deposit(double amount)
    {
        balance += amount;
        cout << "Amount Deposited Successfully\n";
    }

    // Withdraw Money
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient Balance\n";
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal Successful\n";
        }
    }

    // Display Account Info
    void display()
    {
        cout << "\n===== Account Details =====\n";
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }

    // Getter
    double getAccountNumber()
    {
        return accountNumber;
    }

    double getBalance()
    {
        return balance;
    }
};

//  DERIVED CLASS 

class ATM : public BankAccount
{
private:
    int passkey;

public:
    // Set ATM Password
    void setPasskey()
    {
        cout << "Set ATM Passkey: ";
        cin >> passkey;
    }

    // Verify Password
    bool verifyPasskey()
    {
        int pin;

        cout << "Enter Passkey: ";
        cin >> pin;

        if (pin == passkey)
        {
            return true;
        }
        else
        {
            cout << "Incorrect Passkey\n";
            return false;
        }
    }

    // Full Account Creation
    void openAccount()
    {
        createAccount();
        setPasskey();

        cout << "\nAccount Created Successfully\n";
    }

    // ATM Withdraw
    void atmWithdraw()
    {
        if (verifyPasskey())
        {
            double amount;

            cout << "Enter Amount to Withdraw: ";
            cin >> amount;

            withdraw(amount);
        }
    }

    // Balance Check
    void checkBalance()
    {
        if (verifyPasskey())
        {
            cout << "Current Balance: " << balance << endl;
        }
    }
};



int main()
{
    ATM accounts[100];
    int count = 0;

    int choice;

    do
    {
        cout << "\n======= ATM MENU =======\n";
        cout << "1. Create Account\n";
        cout << "2. View All Accounts\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            accounts[count].openAccount();
            count++;
            break;

        case 2:

            for (int i = 0; i < count; i++)
            {
                accounts[i].display();
            }

            break;

        case 3:
        {
            double accNo;
            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (accounts[i].getAccountNumber() == accNo)
                {
                    accounts[i].atmWithdraw();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account Not Found\n";
            }

            break;
        }

        case 4:
        {
            double accNo;

            cout << "Enter Account Number: ";
            cin >> accNo;

            bool found = false;

            for (int i = 0; i < count; i++)
            {
                if (accounts[i].getAccountNumber() == accNo)
                {
                    accounts[i].checkBalance();
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "Account Not Found\n";
            }

            break;
        }

        case 5:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}
