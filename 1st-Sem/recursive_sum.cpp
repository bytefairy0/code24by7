#include <iostream>
using namespace std;

int sum(int a[], int n){
    if (n == 0)
        return 0;
    else
        return a[n-1] + sum(a, n-1);
}

int main(){

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int s = sum(arr, n);
    cout<<s;

    return 0;
}