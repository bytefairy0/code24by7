#include <iostream>
using namespace std;

class Point{
    private:
        int x, y;
    public:
        // Getter function
        int getx() {return x;}
        int gety() {return y;}

        // Setter function
        void setx(int a) {x = a;}
        void sety(int b) {y = b;}

        void display(){
            cout << "("<<x<<","<<y<<")" << endl;
        }
};

class Line{
    private:
        Point p1, p2;
    public:
        //Setter function
        void setp1(Point &p1) {this->p1 = p1;}
        void setp2(Point &p2) {this->p2 = p2;}

        // Getter function
        Point getp1() {return p1;}
        Point getp2() {return p2;}

        // Slope Calculation
        double getSlope(){
            int slope;
            if (p2.getx() - p1.getx() == 0){
                cout << "Slope is undefined" << endl;
                return 0;
            }
            slope = (p2.gety() - p1.gety()) / (p2.getx() - p1.getx());
            return slope;
        }

        void displayLine(){
            cout << "P1 = (" << p1.getx() << "," << p1.gety() << ")" << endl;
            cout << "P2 = (" << p2.getx() << "," << p2.gety() << ")" << endl;
        }
};

int main(){
    Point p1, p2;
    p1.setx(1);
    p1.sety(2);
    p2.setx(5);
    p2.sety(11);

    Line l1;
    l1.setp1(p1);
    l1.setp2(p2);

    cout << "Slope: " << l1.getSlope() << endl;
    cout << "Line: " << endl;
    l1.displayLine();
}