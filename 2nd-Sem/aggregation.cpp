#include <iostream>
#include <vector>
using namespace std;

class Professor{
    string name;
    int employeeID;
    string designation;

    public:
        // setters functions:
        void setName(string n){name = n;}
        void setEmployeeId(int i){employeeID = i;}
        void setDesignation(string d){designation = d;}

        // getter functions
        string getName(){return name;}
        int getEmployeeId(){return employeeID;}
        string getDesignation(){return designation;}
};

class Department{
    string name;
    int deptID;
    vector<Professor> profList;
    // int noOfProfessors; // not needed, vector size can be used

public:
    Department() {
        // no initialization needed for vector
    }

    void setDeptName(string n) {
        name = n;
    }

    string getDeptName() {
        return name;
    }

    void addProfessor(const Professor& P) {
        profList.push_back(P);
    }

    bool deleteProfessor(int id) {
        for (auto it = profList.begin(); it != profList.end(); ++it) {
            if (it->getEmployeeId() == id) {
                profList.erase(it);
                return true;
            }
        }
        return false;
    }

    bool updateProfessor(int id, string newDesignation) {
        for (auto& prof : profList) {
            if (prof.getEmployeeId() == id) {
                prof.setDesignation(newDesignation);
                return true;
            }
        }
        return false;
    }

    void Display() {
        cout << "\n\t--- Department: " << name << " ---" << endl;
        cout << "Professors: " << endl;
        for (size_t i = 0; i < profList.size(); i++) {
            cout << "\n" << i + 1 << ". Name: " << profList[i].getName() << endl;
            cout << "ID: " << profList[i].getEmployeeId() << endl;
            cout << "Designation: " << profList[i].getDesignation() << endl;
        }
    }
};

class University{
    private:
        string name;
        Department* dept;
        int noOfDepartments;
    public:
        University(){
            dept = new Department[noOfDepartments]
        }
        bool addDepartment(Department D){
            dept[noOfDepartments-1] = D;
        }
        bool deleteDepartment(string name){
            for (int i=0; i<noOfDepartments; i++){
                if (dept[i].getDeptName() == name){

                }
            }
        }
}


int main(){

}