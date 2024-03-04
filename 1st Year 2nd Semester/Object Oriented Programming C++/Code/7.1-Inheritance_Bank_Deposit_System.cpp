/****************************************
BANK DEPOSIT SYSTEM
LANGUAGE: C++
LAST MODIFIED: 4 APRIL 2021, 3:01 PM BDST
NISHAT MAHMUD
****************************************/

#include <iostream>
using namespace std;

class Account
{
public:
    string customerName;
    int accountNumber, choice;
    double interest;

    string getName()
    {
        cin.ignore();       //reference: youtu.be/AgS9JSzbvtU
        cout << endl << "Enter the customer name: ";
        getline(cin, customerName);
        return customerName;
    }

    int accountNum()
    {
        cout << "Enter the account number: ";
        cin >> accountNumber;
        return accountNumber;
    }

    int accountType()
    {
        while(1)
        {
            cout << endl << "Enter the account type..." << endl;
            cout << "1. Savings" << endl;
            cout << "2. Current" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            if(choice == 1 || choice == 2)
            {
                break;
            }
            else
            {
                cout << "Wrong Input! Please input the choice again." << endl;
            }
        }

        return choice;
    }
};


class savingsAccount : public Account
{
public:
    double currentDeposit, newDeposit, totalDeposit, withdraw, interest, year;
    int choice;

    void currentBalance()
    {
        while(1)
        {
            cout << endl << "Enter current balance (BDT): ";
            cin >> currentDeposit;

            if(currentDeposit < 0)
            {
                cout << "Invalid Balance! Balance must be 0 or higher amount. Please input again." << endl;
            }
            else
            {
                break;
            }
        }

        while(1)
        {
            cout << endl << "Enter interest rate (in percentage, Ex: 2 or 5 or 10): ";
            cin >> interest;

            if(interest < 0)
            {
                cout << "Invalid Interest! Interest must be 0 or higher percentage. Please input again." << endl;
            }
            else
            {
                break;
            }
        }

        while(1)
        {
            cout << endl << "Enter how many years (floating type allowed): ";
            cin >> year;

            if(year < 0)
            {
                cout << "Invalid Year! Year must be 0 or higher value. Please input again." << endl;
            }
            else
            {
                break;
            }
        }

        while(1)
        {
            cout << endl << "Want to deposit or withdraw?" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            if(choice == 1 || choice == 2)
            {
                break;
            }
            else
            {
                cout << "Wrong Input! Please input a valid choice (1 or 2)." << endl;
            }
        }

        if(choice == 1)
        {
            while(1)
            {
                cout << endl << "Enter new deposit (BDT): ";
                cin >> newDeposit;
                if(newDeposit < 0)
                {
                    cout << "Invalid New Deposit! New deposit might be 0 or higher amount. Please input a valid value." << endl;
                }
                else
                {
                    break;
                }
            }
            cout << "Success! " << newDeposit << " BDT added to the existing balance." << endl;
            totalDeposit = currentDeposit + newDeposit;
            totalDeposit = totalDeposit + (totalDeposit * (interest/100) * year);
        }
        else if(choice == 2)
        {
            currentDeposit = currentDeposit + (currentDeposit * (interest/100) * year);

            while(1)
            {
                while(1)
                {
                    cout << endl << "Enter withdraw amount (BDT): ";
                    cin >> withdraw;

                    if(withdraw < 0)
                    {
                        cout << "Invalid Withdraw Amount! Which can't be negative. Please input a valid value." << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                if(withdraw > currentDeposit)
                {
                    cout << "Can't withdraw more than current balance. Please input a valid value." << endl;
                    cout << "Suggestion: Enter amount between " << currentDeposit << " BDT" << endl;
                }
                else
                {
                    break;
                }
            }

            totalDeposit = currentDeposit - withdraw;
        }
    }

    void savingsAccountDisplay()
    {
        cout << "Account Type: Savings" << endl;
        cout << "Rate of Interest: " << interest << "%" << endl;
        cout << "Year: " << year << " year(s)" << endl;
        cout << "Current Balance: " << totalDeposit << " BDT" << endl << endl << endl << endl;
    }
};


class currentAccount : public Account
{
public:
    double currentDeposit, newDeposit, totalDeposit, withdraw, charge, minimumBalance;
    int choice;

    void currentBalance()
    {

        charge = 0;
        minimumBalance = 1000;
        while(1)
        {
            cout << endl << "Enter current balance (BDT): ";
            cin >> currentDeposit;

            if(currentDeposit < 0)
            {
                cout << "Invalid Balance! Balance must be 0 or higher amount. Please input again." << endl;
            }
            else
            {
                break;
            }
        }

        while(1)
        {
            cout << endl << "Want to deposit or withdraw?" << endl;
            cout << "1. Deposit" << endl;
            cout << "2. Withdraw" << endl;
            cout << "Enter choice: ";
            cin >> choice;
            if(choice == 1 || choice == 2)
            {
                break;
            }
            else
            {
                cout << "Wrong Input! Please input a valid choice (1 or 2)." << endl;
            }
        }

        if(choice == 1)
        {
            while(1)
            {
                cout << endl << "Enter new deposit (BDT): ";
                cin >> newDeposit;
                if(newDeposit < 0)
                {
                    cout << "Invalid New Deposit! New deposit might be 0 or higher amount. Please input a valid value." << endl;
                }
                else
                {
                    break;
                }
            }
            cout << "Success! " << newDeposit << " BDT added to the existing balance." << endl;
            totalDeposit = currentDeposit + newDeposit;
        }
        else if(choice == 2)
        {
            if(currentDeposit > 100)
            {
                while(1)
                {
                    while(1)
                    {
                        cout << endl << "Enter withdraw amount (BDT): ";
                        cin >> withdraw;
                        if(withdraw < 0)
                        {
                            cout << "Invalid Withdraw Amount! Which can't be negative. Please input a valid value." << endl;
                        }
                        else
                        {
                            break;
                        }
                    }

                    if(withdraw > currentDeposit)
                    {
                        cout << "Can't withdraw more than current balance. Please input a valid value." << endl;
                        cout << "Suggestion: Enter amount between " << currentDeposit << " BDT" << endl;
                    }
                    else if(withdraw > currentDeposit-100)
                    {
                        cout << "Can't withdraw balance! Since the current balance of account is less than 1000 BDT." << endl;
                        cout << "So the account must have minimum 100 BDT to pay the withdraw charge. Please input again." << endl;
                        cout << "Suggestion: Enter amount between " << currentDeposit-100 << " BDT" << endl;
                    }
                    else
                    {
                        break;
                    }
                }

                totalDeposit = currentDeposit - withdraw;

                if(totalDeposit < minimumBalance)
                {
                    totalDeposit = totalDeposit - 100;          // charge 100 BDT as final current balance is less than 1000 taka
                    charge = 100;
                }
                else
                {
                    totalDeposit = totalDeposit;
                }

                cout << "Withdraw Charge: " << charge << " BDT" << endl;
                cout << "(Note: If the current balance is less than 1000 BDT, then Withdraw Charge = 100 BDT, otherwise 0 BDT)" << endl;


            }
            else
            {
                cout << "Can't withdraw balance! Since the current balance of account is less than 1000 BDT." << endl;
                cout << "So the account must have minimum 100 BDT to pay the withdraw charge. Thank you." << endl;
                totalDeposit = currentDeposit;
            }
        }
    }

    void currentAccountDisplay()
    {
        cout << "Account Type: Current" << endl;
        cout << "Current Balance: " << totalDeposit << " BDT" << endl << endl << endl << endl;
    }
};


int main()
{
    string Name;
    int accountNumber, accountType, accountChoice;
    int systemChoice;

    while(1)
    {
        cout << "Want to enter Bank Account system?" << endl;
        cout << "1: YES" << endl;
        cout << "Other Key: NO" << endl;
        cout << "Enter choice: ";
        cin >> systemChoice;

        if(systemChoice == 1)
        {
            Account ob;
            Name = ob.getName();
            accountNumber = ob.accountNum();
            accountChoice = ob.accountType();

            if(accountChoice == 1)
            {
                savingsAccount ob1;
                ob1.currentBalance();
                cout << endl << "Customer Name: " << Name << endl;
                cout << "Account Number: " << accountNumber << endl;
                ob1.savingsAccountDisplay();
            }
            else if(accountChoice == 2)
            {
                currentAccount ob2;
                ob2.currentBalance();
                cout << endl << "Customer Name: " << Name << endl;
                cout << "Account Number: " << accountNumber << endl;
                ob2.currentAccountDisplay();
            }
        }

        else
        {
            cout << endl << "Thank you! Press any key to exit from console." << endl << endl;
            break;
        }
    }

    return 0;
}


/**********************

    Assume that a Bank maintains two kinds of accounts for customers, one called as Savings
account and the other is Current account. The savings account provides compound interest
and withdrawal facilities but no check book facility. The current account provides check
book facility but no interest. Current account holders also maintain a minimum balance and
if the balance falls below this level, a service charge is imposed.

    Create a class Account that stores customer name, account number and type of account.
From the derive class cur_acct and sav_acct to make them more specific to their
requirements. Include necessary member functions in order to achieve the following tasks.

    a. Accept deposit from a customer and update the balance.
    b. Display the balance.
    c. Compute the deposit interest.
    d. Permit withdrawal and update the balance.
    e. Check for the minimum balance, impose penalty if necessary, and update the balance.

**********************/
