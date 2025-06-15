// For day number, print the exact date

#include <iostream>
using namespace std;

void findDate(int day);

int main(){

    int day;
    // Ask from user day number
    cout<<"Enter day: ";
    cin>>day;


    findDate(day);

    return 0;
}



void findDate(int day){

    // Assign each month day number, odd upto 7 and even from 8 have 31 days:
    string months[12] = {"January", "February", "March", "April", "May", "June", 
                "July", "August", "September", "October", "November", "December"};


    // Creating string of number of days with same index as month array
    int monthdays[12];
    for (int i=0; i<=12; i++){
        if (i==1){
            
            monthdays[i] = 28;
        }
        else if (i%2==0){
            monthdays[i] = 31;
        }
        else{
            monthdays[i] = 30;
        }

    }

    // Subtract and jump on next number to get the month and date
    for (int j=0; j<12; j++){
        if (day >= monthdays[j]){
            day = day - monthdays[j];
        }
        else {
            cout<<day<<" "<<months[j];
            break;
        }
    }

    

}