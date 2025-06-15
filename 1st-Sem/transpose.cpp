//Taking transpose of 2x2 matrix
#include <iostream>
using namespace std;

int main(){
    int arr[3][3] = {{0,7,9}, {5,3,6}, {8,2,4}};
    int arrt[3][3];
    cout<<"The original matrix is: "<<endl<<endl;
    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            // priting orignal array
            cout<<arr[r][c]<<" ";
            // converting rows into colums
            arrt[r][c] = arr[c][r];
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"Transpose of Matrix is: "<<endl<<endl;;

    for (int r=0; r<3; r++){
        for (int c=0; c<3; c++){
            cout<<arrt[r][c]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}