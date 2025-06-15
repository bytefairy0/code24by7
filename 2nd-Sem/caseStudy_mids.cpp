//  Smart University Management System

#include <iostream>
#include <cstring>
using namespace std;

// Struct for Date
struct Date{
    int day;
    int month;
    int year;
};

// Enum to represent Degree programs
enum DegreeProgram{
    CS,
    IT,
    SE,
    AI
};

// Base Class 
class Person{
    protected:
        string name;
        int age;
        string gender;
    
    public:
        // constructor
        Person(string n, int a, string g): name(n), age(a), gender(g){};

        // Display info
        virtual void getDetails() = 0; // pure virtual function


};


// Student class inheriting from Person
class Student : public Person{
    private:
        DegreeProgram program;
        float grades[5]; // grade for 5 course

    public:
        Student(string n, int a, string g, DegreeProgram p, float g[5]): Person(n, a, g), program(p){
            for (int i=0; i<5; i++){
                grades[i] = g[i];
            }
        }

        float calculate_GPA(int index, float sum){
            // Base case
            if (index == 5){
                return sum;
            }
            // Recursive case
            return calculate_GPA(index + 1, sum + grades[index]);
        }

        float getGPA(){
            float totalSum = calculate_GPA(0, 0.0);
            return totalSum / 5;
        }


        void getDetails() override {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Program: " << program << endl;
            cout << "GPA: " << getGPA() << endl;
        }
};

// Faculty class inheriting from Person
class Faculty : public Person{
    private:
        char* department;
    public:
        Faculty(string n, int a, string g, char* d): Person(n, a, g), department(d){
        department = new char[strlen(d) + 1];
        strcpy(department, d);
        }

        void getDetails() override {
            cout << "Faculty: " << name << endl;
            cout << "Age: " << age << endl;
            cout << "Department: " << department << endl;

        }

        ~Faculty(){
            delete[] department;
        }
};




int main(){

    return 0;
}