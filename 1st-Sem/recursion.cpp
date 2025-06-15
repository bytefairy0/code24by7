#include <iostream>
using namespace std;

// recursive function to calculate power
int power(int x, int n){
    if (n<=0){
        return 1;
    }
    else if (n==1){
        return x;
    }
    else{
        return x* power(x, n-1);
    }
}

int main(){

    int x = 5;
    int n = 3;

    cout << power(x, n);
}