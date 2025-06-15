#include <iostream>
using namespace std;


int add(int a, int b){
    return a + b;
}

// A function that takes a function pointer as an argument
void executeFunction(int (*funcptr)(int, int), int x, int y){
    cout << "Result: " << funcptr(x, y) << endl;
}



int main(){
    // Declare a function pointer and assign it to the add function
    int (*funcptr)(int, int) = add;

    // Call the function using the function pointer
    cout << "Using function pointer directly: " << funcptr(5, 3) << endl;

    // Pass the function pointer to another function
    executeFunction(funcptr, 5, 3);
    // or direclty passing
    executeFunction(add, 59, 9);

    return 0;
}