#include <iostream>
using namespace std;

int main(){

    int m1[2][2], m2[2][2];
    m1[2][2] = {
        {1, 2},
        {3, 4}
    };

    m2[2][2] = {
        {5, 6},
        {7, 8}
    };

    // rows with coloums and then add them
    int product[2][2];
    // 1st multiplying with 1st coloum and then adding the 2nd one:
    for (int c1=0; c1<2; c1++){
        for (int r2=0; r2<2; r2++){
            for (int r1=0; r1<2; r1++){
                for (int c2=0; c2<2; c2++){
                    product[r1][c2] = m1[r1][c1]*m2[r2][c2];
                }
            } 
        }
    }


    // Alternative Approach:
    



    return 0;
}