#include <iostream>
using namespace std;


class Rectangle
{
private:
    float length, width;

public:

    void setLength(float l)
    {
        length = l;
    }

    void setWidth(float w)
    {
        width = w;
    }


    float perimeter()
    {
        float Perimeter = 2*(length + width);
        return Perimeter;
    }


    float area()
    {
        float area = length * width;
        return area;
    }


    void show()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
    }


    int sameArea(Rectangle ob1, Rectangle ob2)
    {
        float area1, area2;

        area1 = ob1.area();
        area2 = ob2.area();

        if(area1 == area2)
            return 1;
        else
            return 0;

    }


};


int main()
{
    int status;
    float l, w;

    Rectangle a, b;

    cout << "Enter the Length and the Width of the Rectangle A: ";
    cin >> l >> w;
    a.setLength(l);
    a.setWidth(w);

    cout << "Enter the Length and the Width of the Rectangle B: ";
    cin >> l >> w;
    b.setLength(l);
    b.setWidth(w);

    cout << "A" << endl;
    a.show();
    cout << "Perimeter: " << a.perimeter() << endl;
    cout << "Area: " << a.area() << endl;

    cout << "B" << endl;
    b.show();
    cout << "Perimeter: " << b.perimeter() << endl;
    cout << "Area: " << b.area() << endl;

    status = a.sameArea(a, b);
    //or status = a.sameArea(a, b);
    if(status == 1)
    {
        cout << endl << "A and B rectangles are equal." << endl;
    }
    else
    {
        cout << endl << "A and B rectangles are not equal." << endl;
    }

    return 0;
}
