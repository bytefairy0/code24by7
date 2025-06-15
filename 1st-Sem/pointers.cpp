#include <iostream>
using namespace std;

int main(){

    int var = 10;
    int* ptr = &var;
    cout << "Value of var: " << var << endl; // 10
    cout << "Value of ptr: " << ptr << endl; // adress also for &var
    cout << "Value of *ptr: " << *ptr << endl; // 10

    int arr[6] = {2, 5, 3, 7, 4, 9};
    int* arr_ptr = arr; // arr_ptr refers to address of 1st element of array
    cout << "arr_ptr " << arr_ptr << endl;
    cout << "arr_ptr[0] " << arr_ptr[0] << endl;
    cout << "arr_ptr[1] " << arr_ptr[1] << endl;

    arr_ptr = &arr[1]; // 5
    int* p1 = arr_ptr;
    int* p2 = p1 + 2; 

    cout << "arr_ptr "<< arr_ptr << endl;
    cout << "p1 " << p1 << endl;
    cout << "p2 " << p2 << endl;
    cout << "p2 - p1 " << p2 - p1 << endl;

    cout << "*p1" << *p1 << endl; // 5
    cout << "*p2" << *p2 << endl; // 7

    // Initialy value at arr[3]
    cout << "arr[3] " << arr[3] << endl;
    *p2 = 89;
    cout << "arr[3] " << arr[3] << endl;

    cout << "(p2+1) " << *(p2 + 1) << endl;


    // Null pointers
    int *ptr1 = 0;// or int *ptr1 = NULL
    

   
    return 0;
}


