#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Matrix{
    private:
        int rows, cols;
        int **arr;
    public:
        Matrix(){
            rows = 0;
            cols = 0;
            arr = nullptr;
        }
        Matrix(int r, int c){
            rows = r;
            cols = c;
            arr = new int*[rows];
            for(int i = 0; i < rows; i++){
                arr[i] = new int[cols];
                for (int j = 0; j < cols; j++){
                    arr[i][j] = rand() % 10; 
                }
            }
        }
        Matrix(int r, int c, int** p){
            rows = r;
            cols = c;
            arr = new int*[rows];
            for(int i = 0; i < rows; i++){
                arr[i] = new int[cols];
                for (int j = 0; j < cols; j++){
                    arr[i][j] = p[i][j]; 
                }
            }
        }

        ~Matrix(){
            for(int i = 0; i < rows; i++){
                delete[] arr[i];
            }
            delete[] arr;
        }

        // Getter and setter methods 
        int getRows() const { return rows; }
        int getCols() const { return cols; }
        int getElement(int r, int c) const { return arr[r][c]; }

        void setElement(int r, int c, int value) { arr[r][c] = value; }

        void multiplyMatrix(int scalar){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    arr[i][j] *= scalar;
                }
            }
        }

        void scalarAddition(int scalar){
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    arr[i][j] += scalar;
                }
            }
        }
        void display() const {
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    cout << arr[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    Matrix m1(3, 3); // Create a 3x3 matrix with random values
    cout << "\nMatrix m1:" << endl;
    m1.display();

    // Multiply m1 by a scalar value
    int scalar = 2;
    m1.multiplyMatrix(scalar);
    cout << "\nMatrix m1 after multiplying by " << scalar << ":" << endl;
    m1.display();

    // Add a scalar value to m2
    scalar = 5;
    m1.scalarAddition(scalar);
    cout << "\nMatrix m1 after adding " << scalar << ":" << endl;
    m1.display();

    return 0;
}
