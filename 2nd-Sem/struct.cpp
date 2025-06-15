#include <iostream>
using namespace std;

struct myStructure{ // structure declaration
    int myNum; // Member (int variable)
    string myString; // Member (string variable)
} ;  // structure variable


struct Emp {
    int eId;
    int sal;
};

// Passing by value
void printmyStructure(myStructure s){
    cout << "myNum: " << s.myNum << endl;
}

// passing by reference 
void updateId(Emp &e){
    e.eId = 1;
}

// passing by pointer
void idIncrement(Emp *e){
    e->eId += 1; // Use arrow operator to access members via pointer
}


//Nested Structures
struct Date {
    int day;
    int month;
    int year;
};

struct Profile {
    string username;
    Date birthday;
};

int main(){


    Emp e1 = {20, 120000};
    updateId(e1);
    cout << e1.eId << endl;
    cout << e1.sal << endl;

    Emp e2 = {1, 12000};
    idIncrement(&e2);
    cout << e2.eId << endl;
    cout << e2.sal << endl;

    Profile user;
    user.username = "tech_geek";
    user.birthday = {21, 1, 1995};
    cout << "User.birthday: " << user.birthday << endl;

    // pointers to structures
    Emp *ptr = &e1;
    cout << "Access via pointer: " << ptr->eId << endl;

    // Arrays of Structures
    Emp group[3];
    group[1] = {4, 2000};
    group[2] = {5, 2300};

    cout << "arrayyyy lalala " << group[1].eId << endl;;


    return 0;
}
