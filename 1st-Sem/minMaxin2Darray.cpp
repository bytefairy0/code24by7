#include <iostream>
using namespace std;

int main(){
    int arr[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    
    int max = arr[0][0];
    int min = arr[0][0];

    for (int i=0; i<3; i++){
        for (int j=0; j<4; j++){
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
            else {
                min = arr[i][j];
            }
        }
    }

    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;


    return 0;
}