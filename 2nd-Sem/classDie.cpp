#include <iostream>
using namespace std;

class die{
    public:
        die(); // default constructor
        int roll(); // returns a random num 
        int getNum() const; // returns the num rolled

    private:
        int num;
};

die :: die(){
    num = 1;
    srand(time(0));
}

int die :: roll(){
    num = rand() % 6 + 1;
    return num;
}

int die :: getNum() const{
    return num;
}


int main(){
    die die1;
    die die2;

    cout << "Die 1:" << die1.getNum() << endl;
    cout << "Die 2:" << die2.getNum() << endl;

    cout << "After rolling die1: " << die1.roll() << endl;
    cout << "After rolling die2: " << die2.roll() << endl;

    cout << "The sum of numbers rolled: " << die1.getNum() + die2.getNum() << endl;

    cout << "After again rolling, the sum of the numbers rolled is: " 
         << die1.roll() + die2.roll() << endl;

    return 0;

}