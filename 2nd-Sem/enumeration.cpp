/*Enumeration (Enum) New data type: 
set of named constants*/

#include <iostream>
using namespace std;

enum Color {
    RED = 1,
    GREEN = 5,
    BLUE // Blue has value 0
};

int main(){
    Color myColor = GREEN;
    if (myColor == RED){
        cout << "The color is red." <<endl;
    } else if (myColor == GREEN){
        cout << "The color is green." <<endl;
    } else if (myColor == BLUE){
        cout << "The color is blue." <<endl;
    }

    return 0;
}