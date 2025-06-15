#include <iostream>
using namespace std;

int main(){
    //cout<<"hello world"<<endl;
    //string text = "I am good";
    //cout<<text<<endl;
    //short sa = 91;
    //cout<<sa<<endl;

    // Add integers
    int n1{0}, n2{0}, n3{0};
    cout << "Enter the first integer: ";
    cin >> n1;
    cout << "Enter the second integer: ";
    cin >> n2;
    n3 = n1 + n2;
    cout << "Sum of the two integers is: " <<n3;
    return 0;
}