#include <iostream>
using namespace std;

struct hourlyDetails{
    double hourlyRate;
    int hoursWorked;
};

union SalaryDetails{
    double monthlySalary;
    hourlyDetails hourlyWage;
};

class Employee{
    public:
        string name;
        int employeeID;
        bool isSalaried;
        SalaryDetails salary;

        void displaySalary(){
            if (isSalaried){
                cout << "Monthly Salary: " << salary.monthlySalary << endl;
            }
            else{
                cout << "Hourly Wage: " << salary.hourlyWage.hourlyRate * salary.hourlyWage.hoursWorked << endl;
            }
        }
};

// Function pointer to display Employee information


int main(){
    Employee E1;
    cout << "Enter the name of Employee: ";
    getline(cin, E1.name);
    cout << "Enter the Employee ID: ";
    cin >> E1.employeeID;
    cin.ignore();
    cout << "Is the employee salaried? (1 for Yes, 0 for No): ";
    cin >> E1.isSalaried;
    cin.ignore();
    if (E1.isSalaried){
        cout << "Enter the monthly salary: ";
        cin >> E1.salary.monthlySalary;
    }
    else{
        cout << "Enter the hourly rate: ";
        cin >> E1.salary.hourlyWage.hourlyRate;
        cout << "Enter the hours worked: ";
        cin >> E1.salary.hourlyWage.hoursWorked;
    }

    cout << "\n\n---Details---\n" << endl;

    E1.displaySalary();

}