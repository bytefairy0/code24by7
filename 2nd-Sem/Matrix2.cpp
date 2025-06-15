#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Matrix{
    private:
        int rows;
        int cols;
        int** matrix;
    
    public: 
        Matrix(int r=3, int c=3): rows(r), cols(c){
            matrix = new int*[rows];
            for (int i=0; i<rows; i++){
                matrix[i] = new int[cols];
            }

        };
        
        void initialize(){
            // Initialize a 3*3 matrix
            for (int i=0; i<rows; i++){
                for (int j=0; j<cols; j++){
                matrix[i][j] = rand() % 100;
            }
        }
        }

        ~Matrix(){
            for (int i=0; i<rows; i++){
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        // Deep copy

        // operation overloading
        bool operator == (const Matrix& other){
            bool equal = true;
            if (this->rows != other.rows || this->cols != other.cols){
                equal = false;
            }
            else{
                for (int i=0; i<rows; i++){
                    for (int j=0; j<cols; j++){
                        if (this->matrix[i][j] != other.matrix[i][j]){
                            equal = false;
                            break;
                        }
                    }
                }
            }
            return equal;
        }

        // + with scalar
        Matrix operator + (const int k){
            Matrix result(rows, cols);

            for (int r=0; r<rows; r++){
                for (int c=0; c<cols; c++){
                    result.matrix[r][c] = this->matrix[r][c] + k;
                }
            }
            return result;
        }

        // + with another matrix
        Matrix operator + (const Matrix& other){
            Matrix result(rows, cols);
            for (int r=0; r<rows; r++){
                for (int c=0; c<cols; c++){
                    result.matrix[r][c] = this->matrix[r][c] + other.matrix[r][c];
                }
            }
            return result;
        }

        // Deep Copy -> Constructor
        Matrix(const Matrix& other){
            rows = other.rows;
            cols = other.cols;

            matrix = new int*[rows];
            for (int i=0; i<rows; i++){
                matrix[i] = new int[cols];
                for (int j=0; j<cols; j++){
                    matrix[i][j] = other.matrix[i][j];
                }
            }
        }

        // = equal to
        Matrix& operator = (const Matrix& other){ //Why to &:
            // returning by reference so chain assighnments a = b = c, 
            // if returned by value, its creates copy of result

            if(this == &other) {return *this;} // self assignment check

            // Deallocate current Matrix -> if skip overwrite matrix pointer
            for (int i=0; i<rows; i++){
                delete[] matrix[i];
            }
            delete[] matrix;

            // copy others data into current
            rows = other.rows; 
            cols = other.cols;
            matrix = new int*[rows];
            for (int r=0; r<rows; r++){
                for (int c=0; c<cols; c++){
                    matrix[r][c] = other.matrix[r][c];
                }
            }
            return *this;
        }

        // MOve assignment operaotr
        Matrix& operator=(Matrix&& other) noexcept{
            if (this==&other){
                return *this;
            }
            // clean up existing resource of This obj holds
            for (int i=0; i<rows; i++){
                delete[] matrix[i];
            }
            delete[] matrix;

            // get resources from other: Take ownership
            rows = other.rows;
            cols = other.cols;
            matrix = other.matrix;

            // leave others in safe place
            other.rows = 0;
            other.cols = 0;
            other.matrix = nullptr;

            return *this;
        }
    
        void print(string label = "") const {
            if (!label.empty()) cout << label << endl;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    cout << matrix[i][j] << "\t";
                }
                cout << endl;
            }
            cout << endl;
        }
        

};


int main(){
        srand(static_cast<unsigned int>(time(0)));
    
        // Step 1: Create & Initialize a Matrix
        Matrix m1(3, 3);
        m1.initialize();
    
        // Step 2: Deep Copy
        Matrix m2 = m1;  // Copy constructor
        cout << "Copied Matrix m2 from m1 using DEEP COPY." << endl;
    
        // Step 3: Add scalar
        Matrix m3 = m1 + 10;
        cout << "Added scalar 10 to m1 → m3 = m1 + 10" << endl;
    
        // Step 4: Matrix + Matrix
        Matrix m4 = m1 + m3;
        cout << "Added m1 and m3 → m4 = m1 + m3" << endl;
    
        // Step 5: Equality check
        if (m1 == m2) {
            cout << "m1 and m2 are EQUAL (deep copied correctly) " << endl;
        } 
        else {
            cout << "m1 and m2 are NOT equal " << endl;
        }
    
        // Step 6: Move Assignment
        Matrix m5;
        m5 = move(m4);  // Move assignment
        cout << "Moved m4 into m5 using MOVE ASSIGNMENT. m4 is now empty." << endl;
        
        m1.print("Matrix m1:");
        m2.print("m2: ");
        m3.print("Matrix m3:");
        m4.print("m4: ");
        m5.print("m5: ");

    
}