// Find out Palindrom numbers bewteen range of numbers

#include <iostream>
using namespace std;

void palindrome(int upperLimit, int lowerLimit);

int main(){
    int start, end;
    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the end of the range: ";
    cin >> end;

    palindrome(start, end);
}


void palindrome(int upperLimit, int lowerLimit){

    cout<<"The palindrome numbers between "<<upperLimit<<" and "<<lowerLimit<<" are: ";

    for (int i=upperLimit; i<=lowerLimit; i++){
        int rev = 0;
        int num = i;
        for (num; num>0; num=num/10){
            int digit = num%10;
            rev = rev*10 + digit;
        }
        if (rev == i){
            cout<<i<<", ";
        }
    }
}