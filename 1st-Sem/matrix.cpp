#include <iostream>
using namespace std;

void diagonalValues(int m[][3], int size){
    cout<<"Diagonal Values of Matrix are: "<<endl;
    for (int r=0; r<size; r++){
        for (int c=0; c<size; c++){
            if (r==c){
                cout<<m[r][c]<<" ";
            }
        }
    }
}


int main(){
    // int matrix1[2][2];
    // diagonalValues(matrix1, 2);

    cout<<"----------------------------------"<<endl;

    //int matrix2[3][3];
    int matrix2[3][3] = {
                {0, 5, 3},
                {2, 1, 4},
                {6, 7, 8}
                };
    diagonalValues(matrix2, 3);


    return 0;
}