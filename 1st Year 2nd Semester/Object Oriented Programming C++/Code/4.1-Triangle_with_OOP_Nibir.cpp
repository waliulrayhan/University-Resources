#include<iostream>
using namespace std;

class Triangle
{
private:
    double base,height;
public:
    Triangle(double b, double h)
    {
        base=b;
        height=h;
    }
    void setBase(double b)
    {
        height=b;
    }
    void setHeight(double h)
    {
        height=h;
    }
    double getBase()
    {
        return base;
    }
    double getHeight()
    {
        return height;
    }
    double getArea()
    {
        return 0.5*base*height;
    }
    void show()
    {
        cout<<"Base : "<<base<<endl;
        cout<<"Height : "<<height<<endl;
        cout<<"Area : "<<0.5*base*height<<endl;
    }
};

int main()
{
    Triangle ob(10.0,20.0);
    Triangle ob1(12.0,8.0);

    cout<<"ob :"<<endl;
    ob.show();
    ob.setHeight(5.0);
    cout<<"New height : "<<ob.getHeight()<<endl;
    cout<<"New Area: "<<ob.getArea()<<endl;

    cout<<"ob1 :"<<endl;
    ob1.show();
    ob1.setHeight(6.0);
    cout<<"New height : "<<ob1.getHeight()<<endl;
    cout<<"New Area: "<<ob1.getArea()<<endl;

    return 0;
}