#include <iostream>
using namespace std;

void increase(void* data, int ptrsize){
    if (ptrsize == sizeof(char)){
        char *ptrchar;

        // typecase data to a char pointer
        ptrchar = (char*)data;

        // Increase the char strored at *ptrchar by 1
        (*ptrchar)++;
        cout << "*data point to a char" << endl;

    }

    else if (ptrsize == sizeof(int)){
        int *ptrint;

        // Typecase data to a int pointer 
        ptrint = (int*)data;

        // increase the int stroed at *ptrchar by 1
        (*ptrint)++;
        cout << "*data point to an int" << endl;
    }  
}

void geek(){
    // Declare a character
    char c = 'x';

    // Declare an integer
    int i = 10;

    // Call increase function using a char and int address
    increase(&c, sizeof(char));
    cout << "The new value of c is: " << c << endl;

    increase(&i, sizeof(i));
    cout << "The new value of i is: " << i << endl;


}


int main(){

    /*  Void pointers are pointers that point to a value that has no type
     (and thus also an undetermined length and undetermined dereferencing properties)
     They have to be first transformed into some other pointer type that points to a concrete data type before being dereferenced. */

    geek();

    return 0;
}