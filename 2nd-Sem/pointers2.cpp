#include <iostream>
using namespace std;

void function(const char** ptr)
{
    char* ptr1;
    ptr1 = (ptr += sizeof(int))[-2];
    cout << *ptr1 << endl;
}

int main(){
    const char* arr[] = { "ant", "bat", "cat", "dog", "egg", "fly" };
    function(arr);

    // int arr[] = {1, 2, 3, 4, 5};
    // cout << *arr << endl;
    // arr = arr + 1;
    return 0;
}