// Find missing in array up to range
#include <iostream>
using namespace std;

int main(){
    int arr[] = {8, 2, 4, 5, 3, 7, 1}                                                                                                                                                                                                                                                           ;
    // Find the sum of arr and sum of n numbers
    int len = sizeof(arr)/sizeof(arr[0]);
    cout<<"len: "<<len<<endl;;
        int arrSum = 0;
        for (int i=0; i<len; i++){
            arrSum += arr[i];
        }
        cout<<"arrSum: "<<arrSum<<endl;
        len++;
        int sum = (len*(len+1))/2;
        cout<<"Sum: "<<sum<<endl;
        int n = sum - arrSum;
        cout<<n;
    

    return 0;
}