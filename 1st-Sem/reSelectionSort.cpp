#include <iostream>
using namespace std;

void swap(int &a, int &b);

void selectionSort(int arr[], int n){
    /*Selection sort selects a key and say it minimum
   it check the next key, if its less, now is is minimum, 
   then it moves the minimum to that index,
   and moves the current key at index to its position*/

   // recurseive case of selection sort:

   // base case
   if (n <= 1){
        return;
   }
   // selection sort
   int min = 0;
   int minIndex = 0;
   for (int i = n-1; i >= 0; i--){
        if (arr[i] < arr[minIndex]){
            minIndex = i;
        }
    }
    swap(arr[minIndex], arr[0]);
    selectionSort(arr + 1, n-1);


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
    selectionSort(arr, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}