/*
class ClassName{
    access_specifier:
    // Body of class
};

ClassName ObjectName;
*/


#include <iostream>
#include <string>

using namespace std;

class Person{
    public:
    // Data members
    string name;
    int age;

    // Member function to introduce the person
    void introduce(){
        cout << "Hi, my name is " << name << " and I am "
        << age << " years old." << endl;
    }
};


int main()
{
    // Create and object of the person class
    Person person1;

    person1.name = "Alice";
    person1.age = 30;

    person1.introduce();

    return 0;
}