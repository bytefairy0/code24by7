#include <iostream>
#include <fstream>
using namespace std;

class Student{
    private:
        int id;
        string name;
        float gpa;
    public:
        void input(){
            cout << "Enter Student ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Student name: ";
            getline(cin, name);
            cout << "Enter GPA: ";
            cin >> gpa;
            cin.ignore();
            cout << "Student record saved!" << endl;
        }

        void saveToFile(string filename){
            ofstream file(filename, ios::app);
            if(file.is_open()){
                file << "ID: " << id << 
                     ", Name: " << name << 
                    ", GPA: " << gpa << endl;

            }
        }

        static void displayAll(string filename){
            ifstream file(filename);
            if(file.is_open()){
                string line;
                cout << "\n\tStudent Records:" << endl;
                while(getline(file, line)){
                    cout << line << endl;
                }
            }
        }
};

void choice(){
    cout << "1. Add Student" << endl;
    cout << "2. Display All Students" << endl;
    cout << "3. Exit" << endl;
}

int main(){
    string filename = "students.txt";
    int c;
    while (true){
        cout << "\nEnter Student Data:\n";
        choice();
        cin >> c;
        cin.ignore();
        switch (c) {
            case 1:
                {
                    Student s;
                    s.input();
                    s.saveToFile(filename);
                    break;
                }
            case 2:
                {
                    Student::displayAll(filename);
                    break;
                }
            case 3:
                break;
            default:
                break;
        }
    }
}