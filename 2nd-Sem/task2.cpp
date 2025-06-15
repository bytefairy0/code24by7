#include <iostream>
#include <fstream>
using namespace std;

class Product{
    private:
        int id;
        string name;
        int quantity;
        float price;
    public:
        void addProduct(){
            cout << "Enter Product ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Product name: ";
            getline(cin, name);
            cout << "Enter quantity: ";
            cin >> quantity;
            cout << "Enter price: ";
            cin >> price;
            cin.ignore();
            cout << "Product record saved!" << endl;
        }

        void saveProduct(string filename){
            ofstream file(filename, ios::app);
            if(file.is_open()){
                file << "ID: " << id << 
                     ", Name: " << name << 
                     ", Quantity: " << quantity << 
                     ", Price: " << price << endl;
            }
        }

        static void displayAll(string filename){
            ifstream file(filename);
            if(file.is_open()){
                string line;
                cout << "\n\tProduct Records:" << endl;
                while(getline(file, line)){
                    cout << line << endl;
                }
            }
        }
};  

void choice(){
    cout << "1. Add Product" << endl;
    cout << "2. Display All Products" << endl;
    cout << "3. Exit" << endl;
}
int main(){
    string filename = "products.txt";
    int c;
    while (true){
        cout << "\nEnter Product Data:\n";
        choice();
        cin >> c;
        cin.ignore();
        switch (c) {
            case 1:
                {
                    Product p;
                    p.addProduct();
                    p.saveProduct(filename);
                }
                break;
            case 2:
                Product::displayAll(filename);
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}