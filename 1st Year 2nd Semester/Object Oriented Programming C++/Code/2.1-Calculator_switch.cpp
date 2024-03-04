#include <iostream>
using namespace std;


//addition
void addition(int x, int y)
{
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int sum = x + y;
    cout << "Summation: " << sum << endl;
}

//subtraction
void subtraction(int x, int y)
{
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int sub = x - y;
    cout << "Subtraction: " << sub << endl;
}


//multiplication
void multiplication(int x, int y)
{
    cout << "Enter two numbers: ";
    cin >> x >> y;

    int mul = x * y;
    cout << "Multiplication: " << mul << endl;
}


//division
void division(int x, int y)
{
    cout << "Enter two numbers: ";
    cin >> x >> y;

    double div = (double)x / y;
    cout << "Division: " << div << endl;
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


        switch(choice)
        {
        case 1:
        {
            addition(x, y);
            break;
        }
        case 2:
        {
            subtraction(x, y);
            break;
        }
        case 3:
        {
            multiplication(x, y);
            break;
        }
        case 4:
        {
            division(x, y);
            break;
        }
        case -1:
        {
            return 0;
        }
        default:
        {
            cout << "Wrong Input! Please input again." << endl;
        }
        }
    }while(choice != -1);
}
