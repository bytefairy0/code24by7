#include <iostream>
#include <cstring>

// use cin.ignore after simple cin >> variable.
// Dont use it after getline(cin, var)

using namespace std;

int main(){

    int id, itemsNo;
    string name, item;
    double price;
    
    for (int i=0; i<3; i++){
        cout << "Id: ";
        cin >> id;
        cin.ignore(); 
        cout << "Name: ";
        getline(cin, name);
        cout << "Item: ";
        getline(cin, item, '\n'); 
        cout << "Number of items: ";
        cin >> itemsNo;
        cin.ignore();
        cout << "Price: ";
        cin >> price;
        cin.ignore(); 

        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "The details are given below: ";
        cout << id << " " << name << " " << item << " " << itemsNo << " " << price << endl;
    }
}