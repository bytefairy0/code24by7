#include <iostream>
using namespace std;

#define PI 3.1415

// Macros with argumetns
#define ADD(x, y) ((x) + y)

#define SQUARE(x) (x * x)


int main(){
    cout << "The value of PI is: " << PI << endl;

    int result = ADD(5, 3);
    cout << "Result: " << result << endl;


    return 0;
}
