#include <iostream>
using namespace std;

int main(){
    string word;
    cout << "Enter a word: ";
    cin >> word;
    cout << "The original word is: "<<word<<endl;
    int len = word.size();

    for (int i=0; i<len; i++){
        if (!((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z'))){
            word[i] = '\0';
        }
    }

    cout<<"Modified string is: "<<word;

    return 0;
}