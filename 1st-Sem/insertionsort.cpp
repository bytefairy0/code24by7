// Recrusive case of Insertion Sort
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    /*In insertion sort select a key starting from index one,
    and move backward, check if its smaller then previous number,
    move that num to next index and so on, then place key 
    at that index.*/

    for (int i=1; i<n; i++){
        int key = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }


}


int main(){
    int arr[] = {25, 7, 3, 11, 32, 19};
    int n = sizeof(arr)/sizeof(arr[0]);

 
    cout<<"Sorted Array is: "<<endl;
    insertionSort(arr, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}