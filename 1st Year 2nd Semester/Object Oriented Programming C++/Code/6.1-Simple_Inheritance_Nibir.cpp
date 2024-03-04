#include<iostream>
using namespace std;

class vehicle
{
public:
    int door,wheel,seat;
    Display()
    {
        cout<<"Number of doors :"<<door<<endl;
        cout<<"Number of wheels :"<<wheel<<endl;
        cout<<"Number of seats :"<<seat<<endl<<endl;
    }
};

class Car: public vehicle
{
public:
    Car(int d,int w,int s)
    {
        door=d;
        wheel=w;
        seat=s;
    }
};
class Motorcycle: public vehicle
{
    public:
    Motorcycle(int d,int w,int s)
    {
        door=d;
        wheel=w;
        seat=s;
    }
    setseats(int Seat)
    {
        seat=Seat;
    }
};
class Truck: public vehicle
{
    public:
    Truck()
    {
        door=2;
        wheel=8;
        seat=10;
    }
    Truck(int d,int w,int s)
    {
        door=d;
        wheel=w;
        seat=s;
    }

};

int main()
{
    Car c(2,4,6);
    Motorcycle m(0,2,2);
    Truck dt,t(1,6,3);
    cout<<"Car:"<<endl;
    c.Display();
    cout<<"Motorcycle:"<<endl;
    m.Display();
    m.setseats(3);
    cout<<"After called setseats function:"<<endl;
    m.Display();
    cout<<"Truck (default constructor ):"<<endl;
    dt.Display();
    cout<<"Truck (constructor with value):"<<endl;
    t.Display();

    return 0;
}
