#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
};

class twoDArray{
    private:
        int size;
        int** arr;

    public:
        twoDArray(int s=2): size(s){
            arr = new int*[size];
            for(int i=0; i<size; i++){
                arr[i] = new int[size];
            }
        }
        ~twoDArray(){
            for(int i=0; i<size; i++){
                delete[] arr[i];
            }
            delete [] arr;
        }
    
    void initialize(){
        // initialize the array with random numbers b/w 0 and 9
        // seed random num generator with current time
        srand(static_cast<unsigned int>(time(0)));
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                arr[i][j] = rand() % 10; // random number between 0 and 9
            }
        }
    }

    void print(){
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void transpose(){
        for (int i=0; i<size; i++){
            for (int j=i+1; j<size; j++){
                swap(arr[i][j], arr[j][i]);
            }
        }
    }

    bool isSymmetry(){
        for (int i=0; i<size; i++){
            for (int j=i+1; j<size; j++){
                if (arr[i][j] != arr[j][i]){
                    return false;
                }
            }
        }
        return true;
    }

    // operator overloading
    twoDArray operator * (const twoDArray& obj){
        twoDArray result(size);
        for (int i=0; i<size; i++){
            for (int j=0; j<size; j++){
                for (int k=0; k<size; k++){
                    result.arr[i][j] += arr[i][k] * obj.arr[k][j];
                }
            }
        }
        return result;
    }
};


int main(){
    twoDArray arr1(3), arr2(3);
    arr1.initialize();
    arr2.initialize();

    cout << "\nArray 1:" << endl;
    arr1.print();
    cout << "Array 2:" << endl;
    arr2.print();

    cout << "\nTranspose of Array 1:" << endl;
    arr1.transpose();
    arr1.print();

    cout << "Transpose of Array 2:" << endl;
    arr2.transpose();
    arr2.print();

    if (arr1.isSymmetry()){
        cout << "\nArray 1 is symmetric" << endl;
    }
    else{
        cout << "\nArray 1 is not symmetric" << endl;
    }

    if (arr2.isSymmetry()){
        cout << "Array 2 is symmetric" << endl;
    }
    else{
        cout << "Array 2 is not symmetric" << endl;
    }

    twoDArray arr3 = arr1 * arr2;   
    cout << "\nMultiplication of Array 1 and Array 2:" << endl;
    arr3.print();

    return 0;
}