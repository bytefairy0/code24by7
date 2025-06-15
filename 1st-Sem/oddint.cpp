// Fibonacci series

#include <iostream>
using namespace std;

int main(){
    // ask user odd negative integer
    int n;
    cout<<"Enter an Odd negative Integer: "<<endl;
    
    do {
        cin>>n;
    }
    while (n > 0 || (n%2==0));

    // Equivalent postive number
    int np = -1*n;

    int a, b, f;
    // add the preceding two numbers
    for (int j=0; j<np; j++){
        if (j<= 1){
            f = j;
        }
        else{
            f = a + b;
        }
        a = b;
        b = f;
        

        cout<<f<<" ";
    }

    return 0;
}