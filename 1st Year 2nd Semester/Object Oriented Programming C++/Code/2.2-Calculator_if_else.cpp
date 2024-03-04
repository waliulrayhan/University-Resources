#include <iostream>
using namespace std;


//addition
void addition(int x, int y)
{
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int sum = x + y;
    cout << "Summation: " << sum << endl << endl;
}

//subtraction
void subtraction(int x, int y)
{
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int sub = x - y;
    cout << "Subtraction: " << sub << endl << endl;
}


//multiplication
void multiplication(int x, int y)
{
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int mul = x * y;
    cout << "Multiplication: " << mul << endl << endl;
}


//division
void division(int x, int y)
{
    cout << "Enter two numbers: ";
    cin >> x >> y;

    double div = (double)x / y;
    if(y == 0)
    {
        cout << "Division: Undefined" << endl << endl;
    }
    else
    {
        cout << "Division: " << div << endl << endl;
    }
}



//main function
int main()
{
    int choice, x, y;
    //user input check
    do
    {
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "-1. EXIT" << endl << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if(choice == 1)
        {
            addition(x, y);
        }
        else if(choice == 2)
        {
            subtraction(x, y);
        }
        else if(choice == 3)
        {
            multiplication(x, y);
        }
        else if(choice == 4)
        {
            division(x, y);
        }
        else if(choice == -1)
        {
            return 0;
        }
        else
        {
            cout << "Wrong Input! Please input again." << endl;
        }
    }while(choice != -1);

    return 0;
}
