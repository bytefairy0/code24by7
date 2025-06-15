#include <iostream>
#include <cstring>
using namespace std;

void bookRecordManagement (int N) {
    int bookID=1, bookCopies;
    string bookName, authorName;

    for (int i=0; i<N; i++) {
        cout << "Enter the information for Book " << i+1 <<endl <<endl;

        cout << "Book ID: " << bookID <<endl;
        bookID++;

        cout << "Title " <<endl;
        cin.ignore();
        getline (cin, bookName);

        cout << "Author " <<endl;
        cin.ignore();
        getline (cin, authorName);

        cout << "Copies available: ";
        cin.ignore();
        cin >> bookCopies;
    }
}

int main () {
    int N;
    cout << "Enter the number of books: " <<endl;
    cin >> N;
    cin.ignore();

    bookRecordManagement(N);
}