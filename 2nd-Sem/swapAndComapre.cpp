#include <iostream>
using namespace std;

template <typename T>
void swapAndCompare(T a, T b){
    T temp = a;
    a = b;
    b = temp;

    cout << "\nAfter swapping: a = " << a << ", b = " << b;

    if (a == b) cout << "a and b are equal." << endl;
    else if (a>b) cout << "a is greater than b" << endl;
    else if (b<a) cout << "b is greater than a" << endl;

}

int main(){
    swapAndCompare<int>(10, 5);

    swapAndCompare<string>("Banana", "Apple");

    swapAndCompare<float>(2.1, 3.5);

}