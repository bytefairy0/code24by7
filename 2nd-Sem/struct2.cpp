#include <iostream>
using namespace std;

struct Struct2; // Forward declaration of Struct2

struct Struct1 {
    int data1;
    Struct2* struct2Ptr; // Pointer to Struct2
    Struct1* next; // Pointer to another Struct1 (self-referencing)
};

struct Struct2 {
    int data2;
    Struct1* struct1Ptr; // Pointer to Struct1
};

int main() {
    Struct1 s1;
    Struct2 s2;

    s1.data1 = 10;
    s2.data2 = 20;

    s1.struct2Ptr = &s2; // Linking Struct1 to Struct2
    s2.struct1Ptr = &s1; // Linking Struct2 to Struct1

    // Example usage
    cout << "Struct1 Data: " << s1.data1 << endl;
    cout << "Struct2 Data: " << s1.struct2Ptr->data2 << endl;
    cout << "Back to Struct1 Data: " << s1.struct2Ptr->struct1Ptr->data1 << endl;

    return 0;
}