#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int main(){
    // ask user for input
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    char* ptr = str;
    // Convert to lowercase
    while (*ptr != '\0'){
        if (islower(*ptr)){
            *ptr = toupper(*ptr);
        }
        ptr++;
    }

    cout << "String in upper case: " << str << endl;


    return 0;
}