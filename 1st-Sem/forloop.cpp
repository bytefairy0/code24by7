#include <iostream>
using namespace std;

int main(){

    int marks;
    cin>>marks;
    int grade;

    if (marks >= 80) 
        grade = 1;
    else if (60 <= marks < 80)
        grade = 2;
    else if (50 <= marks < 60)
        grade = 3;
    else if (40 <= marks < 50)
        grade = 4;
    else if (marks < 40)
        grade = 5;

    switch (grade) {
        case 1:
            cout<<"You scored "<<marks<<"%"<<endl;
            cout<<"You are passed with high distinction"<<endl;
            break;
        case 2:
            cout<<"You scored "<<marks<<"%"<<endl;
            cout<<"You are passed with First division"<<endl;
            break;
        case 3:
            cout<<"You scored "<<marks<<"%"<<endl;
            cout<<"You are passed with Second division"<<endl;
            break;
        case 4:
            cout<<"You scored "<<marks<<"%"<<endl;
            cout<<"You are passed with Third division"<<endl;
            break;
        case 5:
            cout<<"You scored "<<marks<<"%"<<endl;
            cout<<"You are Failed."<<endl;
            break;
        
    }


    return 0;

}