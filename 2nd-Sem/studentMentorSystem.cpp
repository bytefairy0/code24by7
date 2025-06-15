#include <iostream>
using namespace std;

// Mentor structure
struct Mentor{
    string name;
    string department;
};

// Student structure
struct Student{
    string name;
    int id;
    Mentor* mentor; // Pointer to assigned mentor
};


int main(){
    Student students[5];
    Mentor* mentors = new Mentor[1];

    for(int i=0; i<5; i++){
        cout << "\nEnter student details: " << endl;
        cout << "Name: ";
        cin >> students[i].name;
        cout << "ID: ";
        cin >> students[i].id;
        cout << "\nEnter mentor details: " << endl;
        cout << "Name: ";
        cin >> mentors[i].name;
        cout << "Department: ";
        cin >> mentors[i].department;

    }
}