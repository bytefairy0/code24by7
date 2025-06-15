// Print individual numbers and then their sum
#include <iostream>
using namespace std;

int main(){
    int number, digits, sum;
    cout<<"Enter a Number: ";
    cin>>number;

    cout<<"Individual digits are: ";

    do {
        // extract the last digit
        digits = number % 10;
        cout<<digits<<" ";
        sum += digits;
        // remove the last digit
        number /= 10;
    } while (number > 0);
    cout<<endl;
    cout<<"Sum of digits: "<<sum;

}