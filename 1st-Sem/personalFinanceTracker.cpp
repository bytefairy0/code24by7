// Including all the Header files
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <sstream>
#include <limits>

using namespace std;

// Global variables or constants
int MAX_ENTRIES = 30;


// All the functions:
void askUser (bool& type, double& amount, string& category, string& date);


void calculateBalance (float amounts[][2], int currentIndex, float &totalIncome, float &totalExpenses, float &balance);
void addExpenses (bool type, double amount, string category, string date, double amounts[][2], string categories[], string dates[], int &currentIndex);
void viewExpenses (double amounts[][2], string categories[], string dates[], int currentIndex);
void viewExpensesCategorically (string categories[], double amounts[][2], int currentIndex);
void calculateTotalSavings (double amounts[][2]);
void checkExpensesByDate (string dates[], double amounts[][2], string targetDate, int currentIndex);
void displayMenu();



int main() {

    bool type = 0;
    double amount = 0;
    string category = "";
    string date = "";

    string file = "file.txt";
    
    int choice;
    string categories[MAX_ENTRIES] = {}; 
    double amounts[MAX_ENTRIES][2]= {};
    string dates[MAX_ENTRIES] = {};
    int currentIndex = 0;
    int saveIndex = 0;
    
    currentIndex = countEntriesInFile(file);

    // Load Data from file
    loadDataFromFile(file, amounts, categories, dates, currentIndex);

    while (true) {
        displayMenu();
        cout << "Enter the operation you want to add: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1){
            askUser(type, amount, category, date);
            saveDataToFile(file, type, amount, category, date, saveIndex, currentIndex);
            currentIndex++;

        }

        else if(choice==6){
            cout<<"Exiting program successfully!"<<endl;
            break;
        } 

        else {
        loadDataFromFile(file, amounts, categories, dates, currentIndex);
            if (choice == 2){
                viewExpenses(amounts, categories, dates, currentIndex);
            }
                
            else if (choice == 3){
                viewExpensesCategorically(categories, amounts, currentIndex);
            }

            else if (choice == 4) {
                string targetMonth;
                calculateTotalSavings(amounts);
            }

            else if (choice == 5) {
                string targetDate;
                cout<<"Enter the date to check expenses (dd-mm-yy): ";
                getline(cin, targetDate);
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                checkExpensesByDate(dates, amounts, targetDate, currentIndex);
            }
            else {
                cout<<"Invalid choice! Option not available! "<<endl;
            }       
        }
    } 
    return 0; 
}


void displayMenu () {
    cout << endl << "-----Your Personal Finance Tracker-----" <<endl;
    cout << "1. Add Expenses" <<endl;
    cout << "2. View All Expenses" <<endl;
    cout << "3. View All Expenses Categorically" <<endl;
    cout << "4. Check Total Savings" <<endl;
    cout << "5. Check Expenses by Date Modified" <<endl;
    cout << "6. Exit the program!"<<endl;
}


void askUser (bool &type, double &amount, string &category, string &date) {
    cout << "Enter the type of entry (1 for income, 0 for expense)" <<endl;
    cin >> type;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter the amount: " <<endl;
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (type == 0) {
    cout << "Enter the category of the amount: (Food, Electricity, School Bills etc)" <<endl;
    getline(cin, category);
  }
    else {
        category = "Salary";
    }
    
    cout << "Enter the date : " <<endl;
    getline (cin, date);
}


void viewExpenses(double amounts[][2], string categories[], string dates[], int currentIndex) {
    cout << endl;
    cout << endl;

    for (int i = 0; i < currentIndex; i++) {
        cout << "Index: " << i + 1 << endl;
        cout << "Type: " << (amounts[i][1] == 1 ? "Income" : "Expense") << endl;
        cout << "Amount: $" << amounts[i][0] << endl;
        cout << "Category: " << categories[i] << endl;
        cout << "Date: " << dates[i] << endl;
        cout << "----------------------" << endl;
    }
}


void viewExpensesCategorically (string categories[], double amounts[][2], int currentIndex) {
    string enteredCategory;
    cout << "Enter the category you want to see the expenses of: ";
    getline(cin, enteredCategory);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    for (int i=0; i<currentIndex; i++) {
        if (enteredCategory.compare(categories[i]) == 0){
                cout << "Category: " << categories[i] << endl << "Amount: " << amounts[i][0] <<endl;
            }
    }
    
    
}


int countEntriesInFile(string &filename) {
    ifstream inFile(filename);
    int count = 0;
    string line;
    while (getline(inFile, line)) {
        count++;
    }
    return count;
}


void saveDataToFile(string& file, bool type, double amount, string category, string date, int& saveIndex, int currentIndex){
    
    // open file for writing
    ofstream outFile;
    outFile.open(file, ios::app);

    // check if file opened successfully 
    if (!outFile){
        cout<<"Error: COuld not open file for writing."<<endl;
        return;
    }

    // Write each entry into the file
    outFile << currentIndex + 1 << ","  
                << amount << ","
                << type << ","
                << category << ","
                << date << endl;
    
    // close the file
    outFile.close();
    cout << "Data saved successfully to file: " << file <<endl;

}


void loadDataFromFile(string &filename, double amounts[][2], string categories[], string dates[], int& currentIndex){
    ifstream inFile(filename);

    // Check if file opened successfully
    if (!inFile){
        return;
    }
    string line;
    currentIndex = 0;
    while (getline(inFile, line) && currentIndex < MAX_ENTRIES){
        stringstream ss(line);
        string indexStr, amountStr, typeStr, category, date;
        
        // Parse the line into components
        getline(ss, indexStr, ',');
        getline(ss, amountStr, ',');
        getline(ss, typeStr, ',');
        getline(ss, category, ',');
        getline(ss, date, ',');

        // Convert strings to other type
        int index = stoi(indexStr);
        double amount = stod(amountStr);
        double type = stod(typeStr);

         // Check for valid index range
        if (index < currentIndex){
            continue; // if data is already stored in array, don't store it again
        }
        

        // Store data into arrays
        amounts[currentIndex][0] = amount;
        amounts[currentIndex][1] = type;
        categories[currentIndex] = category;
        dates[currentIndex] = date;

        currentIndex++;
    }
    // update current index as last index of file
    inFile.close();
}


void calculateTotalSavings(double amounts[][2]){
    double totalSavings, income, expense;
    for (int i=0; i<MAX_ENTRIES; i++){
        if (amounts[i][1] == 1){
            income += amounts[i][0]; 
        }
        else if (amounts[i][1] == 0){
            expense += amounts[i][0];
        }
    }
    totalSavings = income - expense;
    cout<<"Your total savings are: $"<<totalSavings<<"!"<<endl;
}


void checkExpensesByDate(string dates[], double amounts[][2], string targetDate, int currentIndex){
    bool found = false;

    cout<<"Expense for date: "<<targetDate<<endl;
    for(int i=0; i<currentIndex; i++){
        if(dates[i].compare(targetDate) == 0){
            cout<<"Amounts: $ "<<amounts[i][0]<<endl;
            found=true;
        }
    }
    if(!found){
        cout<<"No expenses for given date! "<<endl;
    }
}