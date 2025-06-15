#include <iostream>
using namespace std;

void swap(int &a, int &b);

void bubbleSort(int arr[], int n){
    /*In bubble sort, the first element goes to end, to its correct postition
    then 2nd element and so on. */

    for (int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }

}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}




int main(){
    int arr[] = {25, 7, 3, 11, 32, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

 
    cout<<"Sorted Array is: "<<endl;
    bubbleSort(arr, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}