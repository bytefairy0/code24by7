#include <iostream>
#include <cstring>
using namespace std;

class Ticket {
public:
    // 1. Enum inside class
    enum TicketType { STANDARD, VIP, STUDENT };

private:
    char customerName[100];
    double price;
    TicketType type;

public:
    // 3. Inline Getter Functions
    const char* getCustomerName() const { return customerName; }
    double getPrice() const { return price; }
    TicketType getType() const { return type; }

    // 3. Setter Declarations (outlined below)
    void setCustomerName(const char* name);
    void setPrice(double p);
    void setType(TicketType t);
};

// 4. Outline Setter Functions
void Ticket::setCustomerName(const char* name) {
    strncpy(customerName, name, sizeof(customerName) - 1);
    customerName[sizeof(customerName) - 1] = '\0';  // ensure null-termination
}

void Ticket::setPrice(double p) {
    price = p;
}

void Ticket::setType(TicketType t) {
    type = t;
}

// 🔁 Helper to convert enum to string
const char* ticketTypeToString(Ticket::TicketType type) {
    switch (type) {
        case Ticket::STANDARD: return "Standard";
        case Ticket::VIP: return "VIP";
        case Ticket::STUDENT: return "Student";
        default: return "Unknown";
    }
}

int main() {
    // 5. Dynamic array of 3 Ticket objects
    Ticket* tickets = new Ticket[3];

    // Assigning values
    tickets[0].setCustomerName("John Doe");
    tickets[0].setType(Ticket::VIP);
    tickets[0].setPrice(20.0);

    tickets[1].setCustomerName("Alice Smith");
    tickets[1].setType(Ticket::STANDARD);
    tickets[1].setPrice(10.0);

    tickets[2].setCustomerName("Bob Johnson");
    tickets[2].setType(Ticket::STUDENT);
    tickets[2].setPrice(15.0);

    // Displaying all ticket info
    for (int i = 0; i < 3; ++i) {
        cout << "Customer: " << tickets[i].getCustomerName() << endl;
        cout << "Ticket Type: " << ticketTypeToString(tickets[i].getType()) << endl;
        cout << "Price: " << tickets[i].getPrice() << " Rs.\n" << endl;
    }

    delete[] tickets; // Free that heap memory ✨
    return 0;
}
