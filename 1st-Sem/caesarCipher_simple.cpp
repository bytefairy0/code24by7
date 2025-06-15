#include <iostream>
using namespace std;

string encrypt(string text, int shift){
    string result = "";

    // traverse text
    for (int i=0; i<text.length(); i++){
        // Encrypt uppercase characters
        if (isupper(text[i])){
            result += char((text[i] + shift - 65) % 26 + 65);
        }
        // Encrupt lowercase letters
        else{
            result += char((text[i] + shift - 97) % 26 + 97);
        }
    }

    return result;
}


int main(){
    string text = "Attact On ENEMY";
    int key = 4;

    string encryptedText = encrypt(text, key);

    cout << "Text: " << text << endl;;
    cout << "Key: " << key << endl;
    cout << "Encrypted text: " << encryptedText << endl;
    cout << "Decrypted text: " << encrypt(encryptedText, -key);

    return 0;
}