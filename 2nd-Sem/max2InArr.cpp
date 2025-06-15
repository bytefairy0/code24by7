#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> arr  = {10, 10, 10};
    int max = arr[0];
    int len = arr.size();
    for (int i=0; i<len; i++){
        if (max < arr[i]){
                max = arr[i];
        }
    }
        
    // now find the 2nd one
    int max2 = -1;
    bool found = false;
    for (int j=0; j<len; j++){
        if (arr[j] != max){
            if (max2 < arr[j]){
                max2 = arr[j];
                found = true;
            }  
            else if (max2 == arr[j]){
                max2 = arr[j];
                found = true;
            }
        }      
    }

    cout << len << endl;
    cout << max2;
}