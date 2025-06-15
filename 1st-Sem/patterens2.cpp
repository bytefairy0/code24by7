//     *
//    * *
//   *   *
//  *     *
// *       *
// **********


#include <iostream>
using namespace std;

int main(){
    
    for (int i=0; i<5; i++){
        
        for (int j=4; j>i; j--){
            cout<<" ";
        }
        cout<<"*";
        for(int j=1; j<=i; j++){
            cout<<" ";
        }

        for(int k=2; k<=i; k++){
            cout<<" ";
        }
        if (i>0){
            cout<<"*";
        }
        cout<<endl;

    }
    for (int l=0; l<=(5*2)-1; l++){
        cout<<"*";
    }

    return 0;
}