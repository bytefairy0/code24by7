#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    // Seed random num generator with current time
    srand(static_cast<unsigned int>(time(0)));

    // Generate and print 10 random numbers
    // random number = low + (rand() % (high - low + 1))
    for (int i=0; i<5; i++){
        int randomNum = 10 + (rand() % 91); // random number between 10 and 100
        cout<<randomNum << endl;
    }

    return 0;
}