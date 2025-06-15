#include <iostream>
using namespace std;

int main(){
    int *ptr = nullptr; // or NULL or 0

    int*p1 = new int;
    int*p2 = new int[5] // allocate memory for an array of integers
    delete p1; // deallocate memory
    delete[] p2; // deallocate memory for an array

}