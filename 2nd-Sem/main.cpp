#include <iostream>
#include "Employee.h"

using namespace std;

int main(){
    const int NUM_EMPLOYEES = 3;
    Employee employees[NUM_EMPLOYEES]; // calls default constructor for each employee
    
    cout << "\n---Initalizing Employees---\n";
    
    // Address objects
    Address addr1("123 Main St", "New York", 10001);
    Address addr2("456 Elm St", "Los Angeles", 90001);

    employees[0] = Employee("Alice", Employee::MANAGER, 120000, addr1); // calls parameterized constructor
    employees[1] = Employee("Bob", Employee::CLERK, 50000, addr2); // calls parameterized constructor   

    employees[2].setName("Charlie"); 
    employees[2].setDesignation(Employee::DEVELOPER);
    employees[2].setSalary(80000);
    employees[2].setAddress(Address("789 Oak St", "Chicago", 60001)); // calls parameterized constructor

    cout << "\n---Displaying Employees---\n";
    for (int i = 0; i < NUM_EMPLOYEES; ++i) {
        employees[i].display(true); // Display with address
    }
}