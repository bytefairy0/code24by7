#include <iostream>
#include <string>
using namespace std;

int SemCourseCount = 3;

// Course structure
struct Course{
    string code;
    string title;
    int credithours;
    char section;
};

struct Semester{
    int n;
    string code;
    Course* courses;
};

struct Student{
    int id;
    string name;
    Course* courses;
};

// Function prototypes
int getCreditHoursForEachStudent(const Student& students, int courseCount);
void DisplayStudentCourses(Student student, int courseCount);
void DisplaySemesterCourse(const Semester& sem);
void RegisterStudentForCourses(Student* student, Semester& sem, int count, int& courseCount);
void addCourse(Semester& sem);



int main(){

    Semester sem;
    // Add courses to Semester
    addCourse(sem);

    // Register Students for courses
    int studentCount;
    cout << "Enter number of students to register: ";
    cin >> studentCount;
    cin.ignore();
    Student* students = new Student[studentCount]; // Dynamically allocate memory for students
    int studentCourseCount = 0;
    RegisterStudentForCourses(students, sem, studentCount, studentCourseCount);

    // Display registered students and their courses
    for (int i=0; i<studentCount; i++){
        cout << "\n\n\n\t---Student Details---" << endl;
        cout << "\nStudent ID: " << students[i].id << endl;
        cout << "Student Name: " << students[i].name << endl;
        DisplayStudentCourses(students[i], studentCourseCount);
        cout << "Total Credit Hours: " << getCreditHoursForEachStudent(students[i], studentCourseCount) << endl;
    }
    
    // Display semester courses
    DisplaySemesterCourse(sem);

    return 0;
}



void addCourse(Semester& sem){
    
    sem.courses = new Course[SemCourseCount]; // Allocate memory for 3 courses
    sem.code = "Spring2025";
    sem.courses[0].code = "CS101";
    sem.courses[0].title = "Introduction to Programming";
    sem.courses[0].credithours = 3;
    sem.courses[0].section = 'A';
    sem.courses[1].code = "CS102";
    sem.courses[1].title = "Data Structures";
    sem.courses[1].credithours = 4;
    sem.courses[1].section = 'B';
    sem.courses[2].code = "MT201";
    sem.courses[2].title = "Linear Algebra";
    sem.courses[2].credithours = 3;
    sem.courses[2].section = 'A';

    // Display courses
    DisplaySemesterCourse(sem);

    cout << "\nDo you want to add more courses? (y/n): ";
    char choice;
    cin >> choice;
    cin.ignore();

    if(choice != 'y'){
        return;
    }
    int i = SemCourseCount;
    int newCourseCount;
    cout << "Enter the number of courses to add: ";
    cin >> newCourseCount;
    cin.ignore();
    SemCourseCount += newCourseCount;

    for (i; i<SemCourseCount; i++){
        cout << "Enter course code: ";
        getline(cin, sem.courses[i].code);
        cout << "Enter course title: ";
        getline(cin, sem.courses[i].title);
        cout << "Enter course credit hours: ";
        cin >> sem.courses[i].credithours;
        cin.ignore();
        cout << "Enter section: ";
        cin >> sem.courses[i].section;
        cin.ignore();
    }
    
}

void RegisterStudentForCourses(Student* student, Semester& sem, int count, int& courseCount){
    for (int i=0; i<count; i++){
        cout << "\nEnter student ID: ";
        cin >> student[i].id;
        cin.ignore();
        cout << "Enter student name: ";
        getline(cin, student[i].name); 
        cout << "How many courses to register for? ";
        int courseCount;
        cin >> courseCount;
        cin.ignore();
        student[i].courses = new Course[courseCount]; // Dynamically allocate memory for courses
        for (int j=0; j<courseCount; j++){
            int choice;
            cout << "Choose course (1-" << SemCourseCount << "): ";
            cin >> choice;
            cin.ignore();
            student[i].courses[j] = sem.courses[choice]; // Assign course from semester to student
        }
    }
}

int getCreditHoursForEachStudent(const Student& student, int courseCount){
    int totalCreditHours = 0;
    for (int i=0; i<courseCount; i++){
        totalCreditHours += student.courses[i].credithours;
    }
    return totalCreditHours;
}

void DisplayStudentCourses(Student student, int courseCount){
    cout << "\nRegistered Courses: " << endl;
    for (int i=0; i<courseCount; i++){
        cout << student.courses[i].code << ": " << student.courses[i].title
        << "," << "Credit Hours: " << student.courses[i].credithours << endl;
    }
    
}

void DisplaySemesterCourse(const Semester& sem){
    cout << "\n\n\t---Semester Courses---" << endl;
    for (int i=0; i<SemCourseCount; i++){
        cout << i << "." << sem.courses[i].code << ": " << sem.courses[i].title
        << "," << "Credit Hours: " << sem.courses[i].credithours << endl;
    }
}

