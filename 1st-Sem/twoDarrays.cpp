#include <iostream>
using namespace std;

int main(){

    int v = 0;
    int arr[2][3];
    for(int r=0; r<2; r++){
        for (int c=0; c<3; c++){
            arr[r][c] = v;
            v++;
            cout<<arr[r][c]<<" ";
        }
        cout<<endl;
    }

    cout<<"-------------------------------------------"<<endl;


    cout<<"The value at index (0, 2) is: "<<arr[0][2]<<endl;

    return 0;
}