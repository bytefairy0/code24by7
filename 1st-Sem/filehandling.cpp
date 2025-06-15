#include <iostream>
#include <fstream>
using namespace std;

int main(){

    fstream myFile;
    // open file for reading
    myFile.open("text.txt", ios::in);
    

    if (!(myFile.is_open())){
        cout << "Unable to open file";
    }

    
    string text;
    while (getline(myFile, text)){
        cout << text << endl;
    }
    myFile.close();

    // opening file agian for writing
    myFile.open("text.txt", ios::out);

    // Writing in file:
    myFile << "Hello, world!" << endl;

    myFile.seekp(0, ios::end); // moving pointer at the end to append
    // appending in file:
    myFile << "I'm not Stupid" << endl;

    


}