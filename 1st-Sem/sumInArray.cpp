#include <iostream>
#include <vector>
using namespace std;

int main(){

    int arr[] = {1, 2, 3, 7, 5};
    int target = 12;
    int len = arr.size();

    int result[2]; // Return starting and ending position

    for (int i=0; i<len; i++){
        int sum = 0;
        for (int j=i+1; j<len; j++){
            if (arr[i] + arr[j] == target){
                result[0] = i;
                result[1] = j;
                
                break;
            }
            else if (arr[i] + arr[j] < target){
                sum += arr[i] + arr[j];
            }
        }
    }




    return 0;
}