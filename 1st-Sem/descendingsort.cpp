#include <iostream>
using namespace std;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// print array in descending order
void bubbleSort(int arr[], int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){\
}


void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }cout << endl;
}

int main(){
    int arr[] = {25, 7, 3, 11, 32, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

 
    cout<<"Sorted Array is: "<<endl;
    bubbleSort(arr, n);
    printArray(arr, n);
    

    return 0;

}