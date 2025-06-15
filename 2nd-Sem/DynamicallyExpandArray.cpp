#include <iostream>
using namespace std;

// Lol this is such a wrong way to do thigs man, you can't just expand array anyways


void expandArray(int* arr, int& size){
    cout << "Enter size of array: ";
    cin >> size;
    for (int i=3; i<7; i++){
        arr[i] = i;
    }
}

int main(){
    int size = 3;
    // if change the size, the array will be reallocated
    int* n = new int[size];
    n[0] = 1;
    n[1] = 2;
    n[2] = 3;
    
    expandArray(n, size);

    for (int i=0; i<size; i++){
        cout << n[i] << endl;
    }

    // Dynamically free memory
    delete[] n;
}