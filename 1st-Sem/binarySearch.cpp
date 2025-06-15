#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target){
    /*In binary search: got to middle then if target is less
    than mid, we move next element to mid and if greater, we move to previous 
    element and search the repeated array
    */

   int low = 0, high = size - 1;
   while (low <= high){
    int mid = (low + high) / 2;
        if (arr[mid] == target){
            return mid;
        }
        else if (arr[mid]<target){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
   }
   return -1;
}


int main(){

    int arr[] = {1, 2, 3, 4, 19, 24, 67, 80};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 67;

    int result = binarySearch(arr, size, target);
    
    cout << result + 1;

}