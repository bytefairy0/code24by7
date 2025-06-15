#include <iostream>
#include <iomanip>
using namespace std;

struct Student{
    string name;
    int rollNum;
    union {
        int marks;
        float scholarshipStatus;
    };
    bool isMarksActive; 
};

void DataInput(Student*& students, int& size, int& studentCount);
void OutputData(Student* students, int studentCount);

int main(){
    int size = 2;
    int studentCount = 0;
    Student* students = new Student[size];

    DataInput(students, size, studentCount);
    OutputData(students, studentCount);

    delete[] students;
    return 0;
}

void DataInput(Student*& students, int& size, int& studentCount){
    while (true){
        if (studentCount >= size){
            size *= 2;
            Student* newStudents = new Student[size];
            for (int i=0; i<studentCount; i++){
                newStudents[i] = students[i];
            }
            delete[] students;
            students = newStudents; // Correctly reassigning the pointer to the new array
        }
            // Note: In C++, when you pass a pointer to a function, and reassign it inside, you’re only changing the local copy.    
            // To change the original pointer, you need to pass it by reference (using `&`). or you can use double pointer
            // (Student** students) and then dereference it inside the function.

        cout << "Enter student name (or -1 to stop): ";
        getline(cin, students[studentCount].name);
        if (students[studentCount].name == "-1") break;

        cout << "Enter roll number: ";
        cin >> students[studentCount].rollNum;
        cin.ignore();

        cout << "Enter marks or scholarship status (1.0): ";
        float input;
        cin >> input;
        cin.ignore();

        if (input < 0){
            cout << "Invalid input. Please enter positive value.\n";
            continue;
        }

        if (input == 1.0){
            students[studentCount].scholarshipStatus = input;
            students[studentCount].isMarksActive = false;
        } else {
            students[studentCount].marks = input;
            students[studentCount].isMarksActive = true;
        }
        studentCount++;
    }
}

void OutputData(Student* students, int studentCount){
    float highest = 0, lowest = 1000, average = 0;
    int totalScholarship = 0, marksCount = 0;

    cout << "\n--- Student Database ---\n";
    for (int i=0; i<studentCount; i++){
        cout << students[i].name << " (" << students[i].rollNum << ") - ";
        if (students[i].isMarksActive){
            cout << "Marks: " << students[i].marks << endl;
            if (students[i].marks > highest) highest = students[i].marks;
            if (students[i].marks < lowest) lowest = students[i].marks;
            average += students[i].marks;
            marksCount++;
        } else {
            cout << "Scholarship: " << students[i].scholarshipStatus << endl;
            totalScholarship++;
        }
    }

    if (marksCount > 0) average /= marksCount;
    
    cout << fixed << setprecision(2);
    cout << "\n--- Statistics ---\n";
    cout << "Highest Marks: " << highest << endl;
    cout << "Lowest Marks: " << lowest << endl;
    cout << "Average Marks: " << average << endl;
    cout << "Scholarship Students: " << totalScholarship << endl;
}
