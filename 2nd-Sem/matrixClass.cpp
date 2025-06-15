#include <iostream>
using namespace std;

class Matrix{
    private:
        int **data; // 2D array to store matrix
        int rows; 
        int cols;


        public:
            // constructor to intialize matrix with 0
            Matrix(int r, int c): rows(r), cols(c){
                // Dynamically allocate memory for matrix
                data = new int*[rows];
                for (int i=0; i<rows; i++){
                    data[i] = new int[cols];
                }
            }

            // destructor to deallocate memory
            ~Matrix(){
                for (int i=0; i<rows; i++){
                    delete[] data[i]; // delete each row
                }
                delete[] data; // delete the array of rows/pointers
    
            }

            // Copy constructor
            Matrix(const Matrix& other) : rows(other.rows), cols(other.columns){
                // Dynamically allocate memory for new matrix
                data = new int*[rows];
                for (int i=0; i<rows; i++){
                    data[i] = new int[cols];
                }// copy data from other matrix
                for (int i=0; i<rows; i++){
                    for (int j=0; j<cols; j++){
                        data[i][j] = other.data[i][j];
                    }
                }
            }

            // Overload assignment operator
            Matrix& operator=(const Matrix& other){
                if (this == &other){ // check for self assignment
                    return *this;
                }

                // Frist deallocates exisiting data
                for (int i=0; i<rows; i++){
                    delete[] data[i];
                }
                delete[] data;

                // Copy data from other matrix
                rows = other.rows;
                cols = other.cols;
                data = new int*[rows]; 
                for (int i=0; i<rows; i++){
                    data[i] = new int[cols];
                }
                for (int i=0; i<rows; i++){
                    for (int j=0; j<cols; j++){
                        data[i][j] = other.data[i][j];
                    }
                }
                return *this;
            }
}


int main(){

}