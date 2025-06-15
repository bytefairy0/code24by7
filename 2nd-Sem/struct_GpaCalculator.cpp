#include <iostream>
using namespace std;

float calculateGPA(int marks[], int ch[], int n){
    float total = 0;
    int total_ch = 0;
    for (int i=0; i<n; i++){
        total += marks[i] * ch[i];
        ch += ch[i];
    }

    return total / total_ch;
}

struct Student{
    string name;
    int regNo;
    string department;
    float gpa;
};

void display(Student s[]){
    cout << "S.No.\tName\tRegNo\tDegree Program\tSGPA" << endl;
    for (int i=0; i<3; i++){
        cout << i+1 << "\t" << s[i].name << "\t" << s[i].regNo << "\t" << s[i].department << "\t" << s[i].gpa << endl;
    }
}

Student getID(Student s[]){
    string degree;
    cout << "Enter the degree program to search: ";
    cin >> degree;
    for (int i=0; i<3; i++){
        if (s[i].department == degree){
            return s[i];
        }
    }
    cout << "No student found with the given degree program." << endl;
}

void swap(Student &a, Student &b){
    Student temp = a;
    a = b;
    b = temp;
}

void bestStudent(Student s[]){
    // Sort the student record
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (s[i].gpa < s[j].gpa){
                swap(s[i], s[j]);
            }
        }
    }
    // displaying sorted record in desending order
    display(s);
    cout << "The best student is: " << endl;
    cout << "\t" << s[0].name << "\t" << s[0].regNo << "\t" << s[0].department << "\t" << s[0].gpa << endl;      
}


int main(){
    Student s[3];
    for (int i=0; i<3; i++){
        cout << "Enter name: ";
        cin >> s[i].name;
        cout << "Enter regNo: ";
        cin >> s[i].regNo;
        cout << "Enter the degree program: ";
        cin >> s[i].department;
        cout << "Enter the number of courses: ";
        int n;
        cin >> n;

        
        int marks[n], ch[n];
        for (int j=0; j<n; j++){
            cout << "Enter the marks of  course " << n << ": ";
            cin >> marks[j];
            cout << "Enter the credit hours of course " << n << ": ";
            cin >> ch[j];
        }

        s[i].gpa = calculateGPA(marks, ch, n);
    }

    display(s);

}