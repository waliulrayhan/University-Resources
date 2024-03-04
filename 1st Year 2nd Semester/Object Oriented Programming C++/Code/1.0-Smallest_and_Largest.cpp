#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    int n, smallest, largest;
    int arr[100];

    cout << "Enter the size of array: ";
    cin >> n;

    cout << "Enter " << n << " elements: ";

    for(int i=0; i<n; i++)      //for loop er baire i er kono porichiti nai, abr declare korte hobe pore use krle.
    {
        cin >> arr[i];
    }

    smallest = arr[0];
    largest = arr[0];

    for(int i=0; i<n; i++)
    {
        if(arr[i] < smallest)
        {
            smallest = arr[i];
        }

        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }

    cout << "The smallest number is: " << smallest << endl;
    cout << "The largest number is: " << largest << endl;

    getch();
}
