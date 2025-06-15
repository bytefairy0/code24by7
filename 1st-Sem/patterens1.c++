
// A
// B A
// C B A
// D C B A


#include <iostream>
using namespace std;

int main(){
    
    for (int i=0; i<=3; i++){
        for (int j=i; j>=0; j--){
            char c = 'A' + j;
            cout<<c<<" ";
        }

        cout<<endl;
    }


    return 0;
}

