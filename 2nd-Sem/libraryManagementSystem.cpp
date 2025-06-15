#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
using namespace std;


struct Book{
    int id;
    string name;
    string author;
    int editionNumber;
    string purchaseDate;

    enum type{
        MAGAZINE,
        JOURNAL,
        STUDY_BOOK
    };
    type bookType;

    bool isIssued = false;
    string issueDate;
    string returnDate;

};


class Librarian{
    private:
        static string password;
        string name;
    public:
        vector<Book>books;
        Librarian(string n): name(n) {}

        void addBook(const Book& b){
            books.push_back(b);
        }

        void issueBook(Person& p, Book& b){
            for (Book& book: books){
                if (book.id == b.id){
                    if (book.isIssued || !p.checkValidity()) {
                        cout<<"Book is not available."<<endl;
                    }
                    else{
                        p.books.push_back(b);
                        p.setIssueDate(b);
                        book.isIssued = true;
                        cout << "Book is Issued." << endl;
                    }
                }
            }
        }

        void returnBook(Person& p, Book& b){
            for (Book& book: books){
                if (book.id == b.id){
                    book.isIssued = false;
                    p.setRetrunDate(b);
                    if (p.checkReturnDate(b)){
                        cout << "Book Returned on time" << endl;
                    }
                    else {
                        cout << "Book Returned late" << endl;
                        cout << "You have to pay fine." << endl;
                    }
                }
            }
        }

};

class Person{ 
    private:
        int id;
        string name;
        string address;
        string phoneNumber;

        enum Identity{
            STUDENT,
            FACULTY
        };

        Identity identity;

    public:
        Person(int id, string n, string a, string p, Identity i): id(id), name(n), address(a), phoneNumber(p), identity(i) {}

        vector<Book>books;

        bool checkValidity(){
            if (Identity::FACULTY && books.size() > 5){
                cout << "Faculty can issue only 5 books." << endl;
                return false;
            }
            else if (Identity::STUDENT && books.size() > 3){
                cout << "Student can issue only 3 books." << endl;
                return false;
            }
            return true;
        }

        void setIssueDate(Book& b){
            for (Book& book: books){
                if (book.id == b.id){
                    tm tm = {0};
                    int year, month, day;
                    cout << "Enter date (YYYY MM DD): ";
                    cin >> year >> month >> day;
                    tm.tm_year = year - 1900; // tm_year is years since 1900
                    tm.tm_mon = month - 1; // tm_mon is 0-11   
                    tm.tm_mday = day; // tm_mday is 1-31
                    mktime(&tm);
                    book.issueDate = to_string(tm.tm_year + 1900) + "-" + to_string(tm.tm_mon + 1) + "-" + to_string(tm.tm_mday);
                    
                }
            }
        }

        void setRetrunDate(Book& b){
            for (Book& book: books){
                if (book.id == b.id){
                    tm tm1 = {0};
                    int year, month, day;
                    cout << "Enter date (YYYY MM DD): ";
                    cin >> year >> month >> day;
                    tm1.tm_year = year - 1900; 
                    tm1.tm_mon = month - 1;
                    tm1.tm_mday = day;
                    mktime(&tm1);
                    book.returnDate = to_string(tm1.tm_year + 1900) + "-" + to_string(tm1.tm_mon + 1) + "-" + to_string(tm1.tm_mday);
                }
            }
        }

        bool checkReturnDate(Book& b){
            for (Book& book: books){
                if (book.id == b.id){
                    istringstream ss1(book.issueDate);
                    istringstream ss2(book.returnDate);
                    tm tm1 = {0};
                    tm tm2 = {0};
                    int year1, month1, day1;
                    int year2, month2, day2;
                    
                    char dash;
                    ss1 >> tm1.tm_year >> dash >> tm1.tm_mon >> dash >> tm1.tm_mday;
                    ss2 >> tm2.tm_year >> dash >> tm2.tm_mon >> dash >> tm2.tm_mday;

                    tm1.tm_year -= 1900; // tm_year is years since 1900
                    tm1.tm_mon -= 1;

                    tm2.tm_year -= 1900;
                    tm2.tm_mon -= 1;

                    // Convert to time_t for comparison
                    time_t t1 = mktime(&tm1);
                    time_t t2 = mktime(&tm2);


                    switch (Identity){
                        case STUDENT: // aLLowed for 14 days
                            tm1.tm_mday += 14;
                            mktime(&tm1);
                            if (mktime(&tm1) < t2){
                                return false;
                            }
                            break;
                        case FACULTY:
                            tm1.tm_mon += 2;
                            mktime(&tm1);
                            if (mktime(&tm1) < t2){
                                return false;
                            }  
                            break; 
                    }
                    return true; 
                }
            }
        }
}; 


int main(){
    Librarian l("Asima");
    Book b1 = {1, "Sapeins", "Yuval Noah Harari", 1, "2022", Book::STUDY_BOOK};
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

    Person p1(1, "Ali", "Lahore", "1234567890", Person::STUDENT);
    Person p2(2, "Sara", "Karachi", "0987654321", Person::FACULTY);
    Person p3(3, "Ahmed", "Islamabad", "1122334455", Person::STUDENT);
    Person p4(4, "Fatima", "Peshawar", "5566778899", Person::FACULTY);
    Person p5(5, "Aisha", "Quetta", "9988776655", Person::STUDENT);

    l.issueBook(p1, b1);
    l.issueBook(p1, b2);
    l.issueBook(p1, b3);
    l.issueBook(p1, b4);

    l.issueBook(p2, b2);
    l.issueBook(p2, b3);
    l.issueBook(p2, b4);

    l.returnBook(p1, b1);


}

    