#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <algorithm> // For std::remove_if
using namespace std;

// Define Book struct with nested enum
struct Book {
    int id;
    string name;
    string author;
    int editionNumber;
    string purchaseDate;

    enum BookType {
        MAGAZINE,
        JOURNAL,
        STUDY_BOOK
    };
    BookType bookType;

    bool isIssued = false;
    string issueDate;
    string returnDate;
};

// Forward declaration of Person class
class Person;

// Define Librarian class
class Librarian {
    private:
        static string password; // Static member declaration
        string name;
    public:
        vector<Book> books;
        Librarian(string n): name(n) {}

        void addBook(const Book& b) {
            books.push_back(b);
        }

        void issueBook(Person& p, Book& b);
        void returnBook(Person& p, Book& b);
};

// Define the static member outside the class
string Librarian::password = "admin123";

// Define Person class
class Person { 
    public:
        enum Identity {
            STUDENT,
            FACULTY
        };

    private:
        int id;
        string name;
        string address;
        string phoneNumber;
        Identity identity;

    public:
        Person(int id, string n, string a, string p, Identity i)
            : id(id), name(n), address(a), phoneNumber(p), identity(i) {}

        vector<Book> books;

        bool checkValidity() {
            if (identity == FACULTY && books.size() >= 5) {
                cout << "Faculty can issue only 5 books." << endl;
                return false;
            }
            else if (identity == STUDENT && books.size() >= 3) {
                cout << "Student can issue only 3 books." << endl;
                return false;
            }
            return true;
        }

        void setIssueDate(Book& b) {
            for (Book& book : books) {
                if (book.id == b.id) {
                    tm tm = {0};
                    int year, month, day;
                    cout << "Enter issue date (YYYY MM DD): ";
                    cin >> year >> month >> day;
                    tm.tm_year = year - 1900; // tm_year is years since 1900
                    tm.tm_mon = month - 1;    // tm_mon is 0-11   
                    tm.tm_mday = day;         // tm_mday is 1-31
                    mktime(&tm);
                    book.issueDate = to_string(tm.tm_year + 1900) + "-" + 
                                    to_string(tm.tm_mon + 1) + "-" + 
                                    to_string(tm.tm_mday);
                    break;
                }
            }
        }

        void setReturnDate(Book& b) {
            for (Book& book : books) {
                if (book.id == b.id) {
                    tm tm1 = {0};
                    int year, month, day;
                    cout << "Enter return date (YYYY MM DD): ";
                    cin >> year >> month >> day;
                    tm1.tm_year = year - 1900; 
                    tm1.tm_mon = month - 1;
                    tm1.tm_mday = day;
                    mktime(&tm1);
                    book.returnDate = to_string(tm1.tm_year + 1900) + "-" + 
                                     to_string(tm1.tm_mon + 1) + "-" + 
                                     to_string(tm1.tm_mday);
                    break;
                }
            }
        }

        bool checkReturnDate(Book& b) {
            for (Book& book : books) {
                if (book.id == b.id) {
                    istringstream issueStream(book.issueDate);
                    istringstream returnStream(book.returnDate);
                    
                    int issueYear, issueMonth, issueDay;
                    int returnYear, returnMonth, returnDay;
                    
                    char dash;
                    issueStream >> issueYear >> dash >> issueMonth >> dash >> issueDay;
                    returnStream >> returnYear >> dash >> returnMonth >> dash >> returnDay;
                    
                    tm issueTm = {0};
                    issueTm.tm_year = issueYear - 1900;
                    issueTm.tm_mon = issueMonth - 1;
                    issueTm.tm_mday = issueDay;
                    
                    tm returnTm = {0};
                    returnTm.tm_year = returnYear - 1900;
                    returnTm.tm_mon = returnMonth - 1;
                    returnTm.tm_mday = returnDay;
                    
                    time_t issueTime = mktime(&issueTm);
                    time_t returnTime = mktime(&returnTm);
                    
                    // Make a copy for deadline calculation
                    tm deadlineTm = issueTm;
                    
                    if (identity == STUDENT) {
                        // Add 14 days for students
                        deadlineTm.tm_mday += 14;
                    } else {
                        // Add 2 months for faculty
                        deadlineTm.tm_mon += 2;
                    }
                    
                    time_t deadlineTime = mktime(&deadlineTm);
                    
                    // Return true if returned on or before deadline
                    return returnTime <= deadlineTime;
                }
            }
            return false; // Book not found
        }
        
        void removeBook(int bookId) {
            books.erase(
                remove_if(books.begin(), books.end(), 
                    [bookId](const Book& b) { return b.id == bookId; }),
                books.end()
            );
        }
        
        Identity getIdentity() const {
            return identity;
        }
}; 

// Implementation of Librarian methods that depend on Person class
void Librarian::issueBook(Person& p, Book& b) {
    for (Book& book : books) {
        if (book.id == b.id) {
            if (book.isIssued) {
                cout << "Book is already issued." << endl;
                return;
            }
            if (!p.checkValidity()) {
                cout << "Cannot issue more books to this person." << endl;
                return;
            }
            
            p.books.push_back(book);
            p.setIssueDate(book);
            book.isIssued = true;
            cout << "Book is Issued." << endl;
            return;
        }
    }
    cout << "Book not found." << endl;
}

void Librarian::returnBook(Person& p, Book& b) {
    for (Book& book : books) {
        if (book.id == b.id) {
            if (!book.isIssued) {
                cout << "This book was not issued." << endl;
                return;
            }
            
            p.setReturnDate(b);
            bool returnedOnTime = p.checkReturnDate(b);
            
            if (returnedOnTime) {
                cout << "Book returned on time." << endl;
            } else {
                cout << "Book returned late." << endl;
                cout << "You have to pay fine." << endl;
            }
            
            book.isIssued = false;
            p.removeBook(b.id);
            return;
        }
    }
    cout << "Book not found." << endl;
}

int main() {
    Librarian l("Asima");
    
    // Create books using the nested enum
    Book b1 = {1, "Sapiens", "Yuval Noah Harari", 1, "2022", Book::STUDY_BOOK};
    Book b2 = {2, "1984", "George Orwell", 1, "2023", Book::STUDY_BOOK};
    Book b3 = {3, "The Alchemist", "Paulo Coelho", 1, "2023", Book::STUDY_BOOK};
    Book b4 = {4, "The Great Gatsby", "F. Scott Fitzgerald", 1, "2023", Book::STUDY_BOOK};
    Book b5 = {5, "To Kill a Mockingbird", "Harper Lee", 1, "2023", Book::MAGAZINE};
    Book b6 = {6, "The Catcher in the Rye", "J.D. Salinger", 1, "2023", Book::MAGAZINE};
    Book b7 = {7, "The Lord of the Rings", "J.R.R. Tolkien", 1, "2023", Book::JOURNAL};
    Book b8 = {8, "Pride and Prejudice", "Jane Austen", 1, "2023", Book::JOURNAL};
    Book b9 = {9, "The Hobbit", "J.R.R. Tolkien", 1, "2023", Book::JOURNAL};
    Book b10 = {10, "Namal", "Nemrah Ahmed", 1, "2014", Book::STUDY_BOOK};
    
    l.addBook(b1);
    l.addBook(b2);
    l.addBook(b3);
    l.addBook(b4);
    l.addBook(b5);
    l.addBook(b6);  
    l.addBook(b7);
    l.addBook(b8);
    l.addBook(b9);
    l.addBook(b10);

    // Create persons using Person::Identity enum
    Person p1(1, "Ali", "Lahore", "1234567890", Person::STUDENT);
    Person p2(2, "Sara", "Karachi", "0987654321", Person::FACULTY);
    Person p3(3, "Ahmed", "Islamabad", "1122334455", Person::STUDENT);
    Person p4(4, "Fatima", "Peshawar", "5566778899", Person::FACULTY);
    Person p5(5, "Aisha", "Quetta", "9988776655", Person::STUDENT);

    // Test issuing books
    l.issueBook(p1, b1);
    l.issueBook(p1, b2);
    l.issueBook(p1, b3);
    l.issueBook(p1, b4); // This should fail for a student

    l.issueBook(p2, b5);
    l.issueBook(p2, b6);
    l.issueBook(p2, b7);
    l.issueBook(p2, b8);
    l.issueBook(p2, b9);
    l.issueBook(p2, b10); // This should fail for faculty

    // Test returning a book
    l.returnBook(p1, b1);

    return 0;
}