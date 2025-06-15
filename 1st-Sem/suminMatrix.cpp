#include <iostream>
using namespace std;

int main(){

    int matrix[3][4] = {
        {1, 5, 9, 0},
        {3, 4, 21, 0},
        {4, 0, 2, 1}
    };

    // rows sum
    cout << "row sum: " ;
    for (int i=0; i<3; i++){
        int s = 0;
        for (int j=0; j<4; j++){
            s += matrix[i][j];
        }
        cout << s << " ";
    }

    cout << endl;

    // coloumns sum
    cout << "coloumn sum: ";
    for (int j=0; j<4; j++){
        int s = 0;
        for (int i=0; i<3; i++){
            s += matrix[i][j];
        }
        cout << s << " ";
    }
    cout << endl;


    return 0;
}