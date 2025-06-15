#include <iostream>
using namespace std;

int main(){

    char name[20];
    char *ptr;

    cout << "Enter your name: ";
    cin.get(name, 20);

    ptr = name;
    cout << "Hello, " << ptr << endl;

    ptr = name + 20;
    cout << ptr << endl;

    return 0;
}