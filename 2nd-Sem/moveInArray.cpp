// Move all neg elements of an array at end without changing orer of positve and negative elemensts;
#include <iostream>
using namespace std;

void newArray(int arr[], int size);

int main(){
    int size;
    cout << "Enter Array size: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter Array elements: ";
    for (int i = 0; i < size; i++){
        cin >> arr[i];
    }

    cout << "Original Array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // Move array elements
    newArray(arr, size);

    cout << "New Array: ";
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

void newArray(int arr[], int size){
    int mindex = 0;
    for (int i=0; i<size; i++){
        int nindex = 0;
        int element;

        for (int j=i; arr[j]>0&&j<size; j++){ // j>0 to move positive first YAYYYYYY
            if (arr[j] > 0){
                element = arr[mindex];
                arr[mindex] = arr[j];
                nindex = j;
                mindex++;
            
            }

            // Move previous positive elements till they reach nindex
            if (nindex >= mindex){
                for (int k=nindex; k>mindex; k--){
                    arr[k] = arr[k-1];
                }
            arr[mindex] = element;
            }
            
        }
    }
        
        
}
