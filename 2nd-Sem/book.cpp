#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T> class Library;  

template <typename T>
class Book {
private:
    string name;
    string author;
    T rating;

public:
    Book() : name(""), author(""), rating(0) {}
    Book(string n, string a, T r) : name(n), author(a), rating(r) {
        if (rating < 0 || rating > 5) {
            throw invalid_argument("Rating must be between 0 and 5!\n");
        }
    }
    friend class Library<T>;  // Added <T> to match Library's template
};

template <typename T>
class Library {
private:
    Book<T>* books;
    int count;
    int capacity;

public:
    Library(int c) : capacity(c), count(0) {
        books = new Book<T>[capacity];
    }

    void expandArray() {
        capacity *= 2;
        Book<T>* newArray = new Book<T>[capacity];
        for (int i = 0; i < count; i++) {
            newArray[i] = books[i];
        }
        delete[] books;
        books = newArray;
    }

    void addBook() {
        if (count == capacity)
            expandArray();

        string name, author;
        T rating;

        cout << "Enter book name: ";
        cin.ignore();  // Clear input buffer
        getline(cin, name);  // Allow spaces in names
        cout << "Enter author name: ";
        getline(cin, author);
        cout << "Enter rating: ";
        cin >> rating;

        try {
            Book<T> b(name, author, rating);  // Fixed: Book<T> instead of Book<U>
            books[count++] = b;
        }
        catch (const exception& e) {
            cout << "Error: " << e.what();
        }
    }

    void display() {
        for (int i = 0; i < count; i++) {
            cout << "Name: " << books[i].name 
                 << " | Author: " << books[i].author 
                 << " | Rating: " << books[i].rating << endl;
        }
    }

    ~Library() {
        delete[] books;
    }
};

int main() {
    Library<int> lib(2);
    int choice;

    while (true) {
        cout << "1. Add Books\n";
        cout << "2. Show Books\n";
        cout << "3. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.addBook();
                break;
            case 2:
                lib.display();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}