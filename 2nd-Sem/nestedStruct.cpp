#include <iostream>
using namespace std;

struct Course;
struct Department;

struct Student {
    int studentId;
    string name;
    Course* enrolledCourses;
    Department* department;
};

struct Course {
    int courseId;
    string courseName;
    Student* enrolledStudents;
    Department* department;
};

struct Department {
    int departmentId;
    string departmentName;
    Course* offeredCourses;
    Student* students;
};

int main() {
    // Create a department
    Department department;
    department.departmentId = 1;
    department.departmentName = "Computer Science";

    // Create a course
    Course course;
    course.courseId = 1;
    course.courseName = "Data Structures";
    course.department = &department;

    // Create a student
    Student student;
    student.studentId = 1;
    student.name = "John Doe";
    student.department = &department;
    student.enrolledCourses = &course;

    // Print the student's information
    cout << "Student Name: " << student.name << endl;
    cout << "Department Name: " << student.department->departmentName << endl;
    cout << "Course Name: " << student.enrolledCourses->courseName << endl;

    // Print the course's information
    cout << "Course Name: " << course.courseName << endl;
    cout << "Department Name: " << course.department->departmentName << endl;
    cout << "Student Name: " << course.enrolledStudents->name << endl;

    // Print the department's information
    cout << "Department Name: " << department.departmentName << endl;
    cout << "Course Name: " << department.offeredCourses->courseName << endl;
    cout << "Student Name: " << department.students->name << endl;

    return 0;
}
int main() {
    // Create a department
    Department department;
    department.departmentId = 1;
    department.departmentName = "Computer Science";

    // Create a course
    Course course;
    course.courseId = 1;
    course.courseName = "Data Structures";
    course.department = &department;

    // Create a student
    Student student;
    student.studentId = 1;
    student.name = "John Doe";
    student.department = &department;
    student.enrolledCourses = &course;

    // Print the student's information
    cout << "Student Name: " << student.name << endl;
    cout << "Department Name: " << student.department->departmentName << endl;
    cout << "Course Name: " << student.enrolledCourses->courseName << endl;

    // Print the course's information
    cout << "Course Name: " << course.courseName << endl;
    cout << "Department Name: " << course.department->departmentName << endl;
    cout << "Student Name: " << course.enrolledStudents->name << endl;

    // Print the department's information
    cout << "Department Name: " << department.departmentName << endl;
    cout << "Course Name: " << department.offeredCourses->courseName << endl;
    cout << "Student Name: " << department.students->name << endl;

    return 0;
}