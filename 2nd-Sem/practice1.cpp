#include <iostream>
using namespace std;

// Overloading << with struct
struct Address{
    int streetNo;
    int houseNo;
    string city;
    string pin;

    // Constructor
    Address(int sNo=0, int hNo=0, string c="", string p="") : streetNo(sNo), houseNo(hNo), city(c), pin(p) {}

    friend ostream& operator<<(ostream& os, const Address& addr){
        os << "Street No: " << addr.streetNo << ", House No: " << addr.houseNo
           << ", City: " << addr.city << ", Pin: " << addr.pin;
        return os;
    }
}

int main(){

}