#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TEAM_SIZE = 4;

class Alien; // forward declaration

class Human{
    public:
        int id;
        string name;
        int totalKills;
        static int totalHumans; 
        
        // Default constructor:
        Human() {
            id = 0;
            name = "";
            totalKills = 0;
        }
        Human(int id, string n): id(id), name(n){
            totalKills = 0;
        }

        ~Human(){
            totalHumans--;
        };

        void attackOnAlien(Alien*& victim); // forward declaration of class works, when you just need type name, not full defintion
        
};



class Alien{
    public:
        int id;
        string name;
        int totalKills;
        static int totalAliens;

        Alien() {
            id = 0;
            name = "";
            totalKills = 0;
        } 

        Alien(int id, string n) : id(id), name(n){
            totalKills = 0;
        }

        ~Alien(){
            totalAliens--;
        };
            //delete this; -> illegal, already deleted

        void attackOnHuman(Human*& victim){
                this->totalKills++;
    
                cout << "Alien "<<this->id<<"("<<this->name<<") killed Human " <<victim->id<<"("<<victim->name<<")" << endl;
                delete victim; // it will triger the victims destructor, so decremenent there
                victim = nullptr; // For this you have to pass reference to pointer
                cout << "Remaining Humans: "<<Human::totalHumans<<", Remaining Aliens: "<<totalAliens<<endl;
        }
};


int Human::totalHumans = 4;
int Alien::totalAliens = 4;


void Human::attackOnAlien(Alien*& victim){
    this->totalKills++;

    cout << "Human "<<this->id<<"("<<this->name<<") killed Alien " <<victim->id<<"("<<victim->name<<")" << endl;
    delete victim;
    victim = nullptr;
    cout << "Remaining Humans: "<<totalHumans<<", Remaining Aliens: "<<Alien::totalAliens<<endl;
}


void humanTeam(Human** humans){
    cout << "\n\n\n\t---Human Team---"<< endl;
    for (int i=0; i<Human::totalHumans; i++){
        humans[i] = new Human(); // create actual object and then assign it
        humans[i]->id = i+1;
        cout << "Enter Human " << i+1 << " name ";
        cin >> humans[i]->name;
    }
}


void alienTeam(Alien** aliens){
    cout << "\n\n\n\t---Alien Team---"<< endl;
    for (int i=0; i<Alien::totalAliens; i++){
        aliens[i] = new Alien();
        aliens[i]->id = i+1;
        cout << "Enter Alien " << i+1 << " name ";
        cin >> aliens[i]->name;
    }
}


void displayResults(){
    cout << "\n\n\n\t---Game Over---"<<endl;
    if (Human::totalHumans > Alien::totalAliens){
        cout<<"Humans Win the Game"<<endl;
    }
    else if(Human::totalHumans < Alien::totalAliens){
        cout<<"Aliens Win the Game"<<endl;
    }
    else{
        cout<<"Game Draw"<<endl;
    }

    cout << "Total Humans: " << Human::totalHumans << endl;
    cout << "Total Aliens: " << Alien::totalAliens << endl;

}


int main(){
    srand(static_cast<unsigned int>(time(0)));

    Human** humans = new Human*[Human::totalHumans]; // array of pointers, pointer to array of human pointers
    Alien** aliens = new Alien*[Alien::totalAliens];

    humanTeam(humans);
    alienTeam(aliens);

    cout << "\n\tATTACK"<<endl;
    while (Human::totalHumans > 0 && Alien::totalAliens > 0){
        int toss = rand() % 2;
        int alien = rand() % TEAM_SIZE;
        int human = rand() % TEAM_SIZE;
        if (aliens[alien] == nullptr || humans[human] == NULL){
            continue;
        }
        if (toss) {aliens[alien]->attackOnHuman(humans[human]);} // use arrow to access
        else {humans[human]->attackOnAlien(aliens[alien]);}
    }

    displayResults();

    // Clean Memory
    for (int i=0; i<TEAM_SIZE; i++){
        delete humans[i];
        delete aliens[i];
    }
    delete[] humans;
    delete[] aliens;
}