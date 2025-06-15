

#ifndef Employee_H // prevent mulitple inlusions
#define Employee_H

#include <iostream>
#include <string>
#include <algorithm> // for std::max,min,sort,reverse,copy,find,remove
using namespace std;

#define MAX_SAlARY 100000

struct Address{ //You can define constructors (default, parameterized, copy, move) within a struct
    string street;
    string city;
    int zipCode;

    // Default constructor
    Address() : street(""), city(""), zipCode(0) {}

    // Parameterized constructor
    Address(string s, string c, int z) : street(s), city(c), zipCode(z) {}
};

class Employee{
    public:
        enum Designation{MANAGER, CLERK, DEVELOPER, UNKNOWN};
    private:
        string name;
        Designation designation;
        double salary;
        Address address;
    
    // Helper function to convert Designation enum to string
    string getDesginationString() const {
        switch (designation) {
            case MANAGER: return "Manager";
            case CLERK: return "Clerk";
            case DEVELOPER: return "Developer";
            case UNKNOWN: 
            default: return "Unknown";
        }
    }

    public:
        // Constructors
        Employee() : name(""), designation(UNKNOWN), salary(0.0){}

        Employee(const string& n, Designation d, double s, const Address& a): 
                name(n), designation(d), address(a) {
            salary = min(double(MAX_SAlARY), s); // Ensure salary does not exceed MAX_SALARY
        }

        ~Employee() {
            cout << "Destructor called for " << name << endl;
        }

        // Function overloading

        void display() const{
            cout << "\n-------------------------\n";
            cout << "Name: " << name << endl;
            cout << "Designation: " << getDesginationString() << endl;
            cout << "Salary: " << salary << endl;
            cout << "--------------------------\n";
        }

        void display(bool showAddress) const{
            display(); // Call the main display function
            if (showAddress) {
                cout << "Address: " << address.street << ", " << address.city << ", " << address.zipCode << endl;
            }
        }

        void setName(const string& n) { name = n; }
        void setDesignation(Designation d) { designation = d; }
        void setSalary(double s) { salary = min(double(MAX_SAlARY), s); } // Ensure salary does not exceed MAX_SALARY
        void setAddress(const Address& a) { address = a; }
};

#endif



