#include <iostream>
using namespace std;

int main(){
    int const size = 5;

    // four arrays of numbers, square, cube, sum
    int numbers[size], squares[size], cubes[size], sums[size];

    // store values in arrays:
    for (int i = 0; i < size; i++) {
        numbers[i] = i;
        squares[i] = i * i;
        cubes[i] = i * i * i;
        sums[i] = numbers[i] + squares[i] + cubes[i];
    }

    // print numbers
    cout << "Numbers:\t";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << "\t";
    }
    cout << endl;

    // print squares
    cout << "Squares:\t";
    for (int i = 0; i < size; i++) {
        cout << squares[i] << "\t";
    }
    cout << endl;

    // print cubes:
    cout << "Cubes:\t";
    for (int i = 0; i < size; i++) {
        cout << cubes[i] << "\t";
    }
    cout << endl;

    // print sums
    cout << "Sums:\t";
    for (int i = 0; i < size; i++) {
        cout << sums[i] << "\t";
    }
    cout << endl;

    // calculate grandtotal 
    int grandtotal = 0;
    for (int i = 0; i < size; i++) {
        grandtotal += sums[i];
    }
    cout << "Grandtotal: " << grandtotal << endl;

}