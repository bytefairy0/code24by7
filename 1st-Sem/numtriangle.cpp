// Print triangle of numbers

#include <iostream>
using namespace std;

int main(){
    int i;
    for (i=1; i<=5; i++){
        for (int j=5; j>i; j--){
            cout<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}