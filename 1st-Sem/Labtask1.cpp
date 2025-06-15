#include <iostream>
using namespace std;

int main(){
    


// Task 1: Determine even or odd
    int digit;
    cin>>digit;

    if (digit % 2 == 0){
        cout<<digit<<" is even.\n";
    }
    else{
        cout<<digit<<" is odd.\n";
    }


// Task 2: Check if character is vowel or constant
    char l;
    cin>>l;
    if (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u' ||
    l == 'A' || l == 'E' || l == 'I' || l == 'O' || l == 'U') {
        cout<<l<<" is a vowel.\n";
    }
    else {
        cout<<l<<" is a consonant.\n";
    }

// Task 3: check percentage of student using swtich case
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


    // Task 4: Tax Bracket Calculation
    int income;
    cin>>income;

   if (income < 50000){
        cout<<"No tax.\n";
    }
    else if (50000 <= income <= 100000){
        cout<<"10% tax.\n";
    }
    else if (100000 < income <= 150000){
        cout<<"20% tax.\n";
    }
    else if (income > 150000){
        cout<<"30% tax.\n";
    }
    return 0;
}