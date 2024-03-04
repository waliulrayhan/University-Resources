#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int id;             //Employee id
    int type;           //1 = employee, 2 = manager
    string name;        //Employee name
    double baseSalary;  //Base salary

public:
    //Constructor
    Employee(int _id, string _name, int _type, double _baseSalary)
    {
        id = _id;
        name = _name;
        type = _type;
        baseSalary = _baseSalary;
    }

    //id mutator
    void setID(int x)
    {
        id = x;
    }

    //id accessor
    int getID()
    {
        return id;
    }

    //name mutator
    void setName(string x)
    {
        name = x;
    }

    //name accessor
    string getName()
    {
        return name;
    }

    //sets base salary
    void setBaseSalary(double bs)
    {
        baseSalary = bs;
    }

    //if manager, add 10% to base salary
    double getSalary()
    {
        double salary;
        if(type == 1)
        {
            salary = baseSalary;
        }

        else if(type == 2)
        {
            salary = baseSalary + (baseSalary*.1);
        }
        return salary;
    }

    //display all the info of an employee
    void Display()
    {
        cout << endl << "Name: " << getName() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Type: " << type << endl;
        cout << "Salary: " << getSalary() << endl << endl;
    }

};

int main()
{
    int id, type;
    string name;
    double baseSalary;

    cout << "Enter your ID: ";
    cin >> id;
    cout << "Enter your Name: ";
    cin >> name;
    cout << "Enter your Type (1 for Employee, 2 for Manager): ";
    cin >> type;
    cout << "Enter your Base Salary: ";
    cin >> baseSalary;

    Employee ob1(id, name, type, baseSalary);
    ob1.Display();

    cout << "Enter your ID: ";
    cin >> id;
    cout << "Enter your Name: ";
    cin >> name;
    cout << "Enter your Type (1 for Employee, 2 for Manager): ";
    cin >> type;
    cout << "Enter your Base Salary: ";
    cin >> baseSalary;

    Employee ob2(id, name, type, baseSalary);
    ob2.Display();

}
