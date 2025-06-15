// Lets try selection sort by iterative case
#include <iostream>

using namespace std;

//Two swap two numbers
void swap(int &a, int &b);


void selectionSort(int arr[], int n){
   /*Selection sort selects a key and say it minimum
   it check the next key, if its less, now is is minimum, 
   then it moves the minimum to that index,
   and moves the current key at index to its position*/

   // Find the smallest and swap it with the current one:
   for (int i=0; i<n; i++){
    int minIndex, minNum;
    minIndex = i;
    minNum = arr[i];
    for (int j=i+1; j<n; j++){
        if (minNum > arr[j]){
            minNum = arr[j];
            minIndex = j; 
        }
    }
    swap(arr[i], arr[minIndex]);
    
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
    selectionSort(arr, n);
    for (int i=0; i<n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}