#include<iostream>
using namespace std;
int main()
{
    int array[2][100], n, w, i, curw, used[100], maxi = -1, totalprofit = 0;
    cout << "Enter number of objects: ";
    cin >> n;
    cout << "Enter the weight of the knapsack: ";
    cin >> w;

    for (i = 0; i < n; i++)
    {
        cout << "\nEnter weight of object " << i+1 << ": ";
        cin >> array[0][i];
        cout << "Enter profit of object " << i+1 << ": ";
        cin>> array[1][i];
    }
    for (i = 0; i < n; i++)
    {
        used[i] = 0;
    }
    curw = w;
    cout << endl;
    cout << endl;
    cout<<"Object\t\t" <<"Weight\t\t"<<"Profit\t\t"<<"FreeSpace\t\t"<<endl;
    while (curw >= 0)
    {
        maxi = -1;
        for (i = 0; i < n; i++)
        {
            if ((used[i] == 0) && ((maxi == -1) || (((float) array[1][i]/(float) array[0][i]) > ((float) array[1][maxi]/ (float) array[0][maxi]))))
            {
                maxi = i;
            }
        }
        used[maxi] = 1;
        curw -= array[0][maxi];
        totalprofit += array[1][maxi];
        if (curw >= 0)
        {
            cout << maxi + 1 << "\t\t"<< array[0][maxi] <<"\t\t" << array[1][maxi]<< "\t\t" << curw;
        }
        else
        {
            cout << maxi + 1 << "\t\t"<< (array[0][maxi] + curw) << "\t\t"<< (array[1][maxi] / array[0][maxi]) * (array[0][maxi]+ curw) << "\t\t" << curw + array[0][maxi];
            totalprofit -= array[1][maxi];
            totalprofit += ((array[1][maxi] / array[0][maxi]) * (array[0][maxi]+ curw));
        }
        cout<<endl;
    }
    cout << "\nMaximum Profit: " << totalprofit << endl;
    return 0;
}
