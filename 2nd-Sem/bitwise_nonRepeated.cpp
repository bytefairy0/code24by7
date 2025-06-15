// Using XOR operator: ^, xor of identical numbers is 0, xor of 0 and a number is the number itself

#include <iostream>
using namespace std;

int findUnique(int arr[], int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans ^= arr[i];
    }
    return ans;
}

int main(){
    int arr[] = {4, 1, 2, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "The unique element is: " << findUnique(arr, n) << endl;
}