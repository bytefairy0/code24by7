#include <iostream>
using namespace std;

int main(){
    
    // Print straight stairs

    int four = 0;

    for (int i=0; i<16; i++){
  
        // I want to run a loop for four times , and first 6 times, then 12 and then 18...
        int l = 6*four;
        for (int k=0; k<l; k++){
            if (k==0){
                cout<<"#";
            }
            else{
                cout<<" ";  
            }
                
        }
        if (i%4==0){
            four++;
        }

        for (int j=1; j<6; j++){
            if (i%4==0){
                cout<<"#";
            }   
        }
        cout<<"#";
        
        cout<<endl;
    }
    for (int i=0; i<32; i++){
        cout<<"#";
    }

    return 0;
}
