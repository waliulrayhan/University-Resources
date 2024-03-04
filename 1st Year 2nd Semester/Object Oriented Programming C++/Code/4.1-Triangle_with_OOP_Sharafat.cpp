#include<iostream>
using namespace std;
class tringle
{
private:
    double height;
    double base;
public:
    tringle(double h,double b)
    {
        height=h;
        base=b;
    }
    void set_height(double x)
    {
        height=x;
    }
    double get_heigth()
    {
        return height;
    }
    void set_base(double x)
    {
        base=x;
    }
    double get_base()
    {
        return base;
    }
    double get_area()
    {
        double area;
        area=base*height/2;
        return area;
    }
    void show()
    {
        cout<<"Base:"<<get_base()<<endl<<"Height:"<<get_heigth()<<endl<<" Area:"<<get_area()<<endl;
    }
};
int main()
{
    tringle ob(5,10);
    ob.show();
    ob.set_height(10);
    //ob.set_base(10);
    ob.show();
}
