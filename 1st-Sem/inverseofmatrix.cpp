// Taking inverse of Matrix
#include <iostream>
using namespace std;

int main(){
    int matrix[2][2] = {{0,5}, {7,3}};
    // Print original matrix
    cout<<"The Matrix is:"<<endl;
    for(int r=0; r<2; r++){
        for (int c=0; c<2; c++){
            cout << matrix[r][c] << " ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    // First find determinent of matrix
    int det = (matrix[0][0]*matrix[1][1]) - (matrix[0][1]*matrix[1][0]);
    
    //now find the adjoint of matrix:
    float adjoint[2][2];
        // interchange diagnal enteries and change sign of other entries
    for(int r=0; r<2; r++){
        for (int c=0; c<2; c++){
            if(r==c){
                adjoint[r][c] = matrix[1-r][1-c];
            }
            else{
                adjoint[r][c] = -matrix[r][c];
            }
        }
    } 

    cout<<"Inverse of Matrix is: "<<endl;
    float inverse[2][2];
    for (int r=0; r<2; r++){
        for (int c=0; c<2; c++){
            inverse[r][c] = adjoint[r][c] / det;
            cout<<inverse[r][c]<<" ";
        }
        cout<<endl;
    }




    return 0;
}