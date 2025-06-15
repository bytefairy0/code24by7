// Print pyramids of stars

#include <iostream>
using namespace std;

int main(){
    int i, j, k, l;

    for (i=0; i<5; i++){
        for (j=4; j>i; j--)
        {
            cout<<"-";
        }
        for (k=0; k<=i; k++){
            cout<<"#";

        }
        for (l=1; l<=i; l++){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}