#include <iostream>
#include <cstring>

using namespace std;

void stringFunctions(){
    // 1. String Concatenation
    char str1[50] = "Hello, "; // increasing size to accomdate concatenated string
    char str2[] = "World!";
    cout << strcat(str1, str2) << endl;
    
    // 2. Copy string
    char str3[] = "Hello, World!";
    char str4[100];
    strcpy(str4, str3);
    
    // compare string
    char str5[] = "Hello, World!";
    char str6[] = "Hello, World!";
    char str7[] = "Hello, US";
    if (strcmp(str5, str6) == 0){
        cout << "Both strings are equal" << endl;
    }
    cout << "str 5 and 6: " << strcmp(str5, str6) << endl;
    cout << "str 7 and 6: " << strcmp(str7, str6) << endl;

    // 4. Length of string
    char str8[] = "Hello, World!";
    cout << strlen(str8) << endl;

    // Assign string
    char str9[50];
    str

    // Find substring
    string str10 = "Itss Mee lalalal";
    string str11 = str10.substr(3, 7);
    cout << "Substring: " << str11 << endl;

    // Replace string
    string str12 = "Ofc, I am working";
    str12.replace(str12.find("working"), 7, "sleeping");
    cout << "Replaced string: " << str12 << endl;


}


int main(){
    stringFunctions();
    return 0;
}