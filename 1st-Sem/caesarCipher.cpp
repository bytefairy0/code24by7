#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// Function to encrypt a file using a simpe Caesar Cipher
void encryptFile(const string& inputFile, const string& outputFile, int shift){
    ifstream inFile(inputFile, ios::binary);
    ofstream outFile(outputFile, ios::binary);

    if (!inFile){
        cerr << "Error opening input file: " << inputFile << endl;
        return;
    }

    if (!outFile){
        cerr << "Error opening output file: " << outputFile << endl;
        return;
    }

    char ch;
    while (inFile.get(ch)){
        // encrypt the character by shifting the ASCII value
        if (isalpha(static_cast<unsigned char>(ch))){
            char base = isupper(static_cast<unsigned char>(ch)) ? 'A' : 'a';
            ch = static_cast<char>(base + (ch - base + shift + 26) % 26);
        }
        outFile.put(ch);
    }

    inFile.close();
    outFile.close();
    cout << "File encrypted successfull." << endl;
}

// Function to decrypt a file encrypted with above
void decryptFile(const string& inputFile, const string& outputFile, int shift){
    // Decryption is reversing the encryption process
    encryptFile(inputFile, outputFile, -shift);
}


int main(){
    string inputFile = "plain.txt";
    string encryptedFile = "encryped.txt";
    string decryptedFile = "decrypted.txt";
    int shift = 4;

    // Encrpt the file
    encryptFile(inputFile, encryptedFile, shift);

    // Decrypt file to verify
    decryptFile(encryptedFile, decryptedFile, shift);

    return 0;

}