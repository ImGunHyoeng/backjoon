#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <string>
class Person
{
public:
    string name;
    int age;
    Person() :name(new char[100]), age(0)
    {

    }
    virtual void getdata() = 0;


    virtual void putdata() = 0;

    ~Person()
    {

    }
};

class Professor :public Person
{
public:
    int publications;
    static int Professor_id;
    int cur_id;
    Professor() :publications(0)
    {}
    virtual void getdata() override
    {
        cin >> name;
        cin >> age;
        cin >> publications;
        Professor_id++;
        cur_id = Professor_id;
    }

    virtual void putdata() override
    {
        cout << name << ' ' << age << ' ' << publications << ' ' << cur_id << '\n';
    }

};
int Professor::Professor_id = 0;

class Student :public Person
{
public:
    int* marks;
    static int Student_id;
    int cur_id;
    Student() :marks(new int[6])
    {

    }
    virtual void getdata() override
    {
        cin >> name;
        cin >> age;
        for (int i = 0; i < 6; i++)
            cin >> marks[i];
        Student_id++;
        cur_id = Student_id;
    }

    virtual void putdata() override
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            sum += marks[i];
        cout << name << ' ' << age << ' ' << sum << ' ' << cur_id << '\n';
    }
    ~Student()
    {
        delete[] marks;
    }
};
int Student::Student_id = 0;

int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
    Person* per[n];

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
