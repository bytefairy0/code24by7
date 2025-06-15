#include <iostream>
using namespace std;

int main(){

    int num1 = 10;
    const int *ptr = &num1; // pointer to constant integer
    // *ptr += 1; // error: assignment of read-only location ‘* ptr’
    ptr = &num1;
    ptr += 1;
    cout << *ptr << endl;
    
    int num2 = 20;
    int *const ptr2 = &num2; // constant pointer to integer
    *ptr2 += 1;
    // ptr2 = &num2; // error: assignment of read-only variable ‘ptr2’
    cout << *ptr2 << endl;


    

}