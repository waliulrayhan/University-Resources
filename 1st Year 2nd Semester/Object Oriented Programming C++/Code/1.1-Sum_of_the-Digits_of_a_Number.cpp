/**
sum_of_the_int (snake case)
sumOfTheInt (camel case)
**/

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int num, sum, digit;
    cout << "Enter a positive number: ";
    cin >> num;

    sum = 0;
    digit = 0;

    while(num != 0)
    {
        digit = num % 10;
        sum = sum + digit;
        cout << digit << " ";
        num = num / 10;
    }

    cout << endl << "Summation: " << sum;

    getch();
}
