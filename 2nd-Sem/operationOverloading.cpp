#include <iostream>
using namespace std;

// class to represent complex numbers
class Complex{
    private:
        double real;
        double imag;

    public:
        // constructor
        Complex(double r=0, double i=0) : real(r), imag(i){};

        // overload the + operator to add two complex numbers
        Complex operator + (const Complex& obj){
            Complex result;
            result.real = real + obj.real;
            result.imag = imag + obj.imag;
            return result;
        }

        // Overload - operator to subtract two complex numbers
        Complex operator - (const Complex& obj){
            Complex result;
            result.real = real - obj.real;
            result.imag = imag - obj.imag;
            return result;
        }

        // Overload * operator to multiply two complex numbers
        Complex operator * (const Complex& obj){
            Complex result;
            result.real = real * obj.real - imag * obj.imag;
            result.imag = real * obj.imag + imag * obj.real;
            return result;
        }

        // Overload / operator to divide two complex numbers
        Complex operator / (const Complex& obj){
            Complex result;
            double denominator = obj.real * obj.real + obj.imag * obj.imag;
            result.real = (real * obj.real + imag * obj.imag) / denominator;
            result.imag = (imag * obj.real - real * obj.imag) / denominator;
            return result;
        }

        // Overload the == operator to compare two complex number
        bool operator == (const Complex& obj){
            return (real == obj.real && imag == obj.imag);
        }

        // Overload the << operator to print complex numbers
        friend ostream& operator << (ostream& os, const Complex& obj);

        // Overload the >> operator to input complex numbers
        friend istream& operator >> (istream& is, Complex& obj);
};

// Overload the << operator for output
ostream& operator << (ostream& os, const Complex& obj){
    os << obj.real;
    if (obj.imag >= 0){
        os << " + " << obj.imag << "i";
    }
    else{
        os << " - " << -obj.imag << "i";
    }
    return os;
}

// Overload the >> operator for input
istream& operator >> (istream& is, Complex& obj){
    cout << "Enter real part: ";
    is >> obj.real;
    cout << "Enter imaginary part: ";
    is >> obj.imag;
    return is;
}


int main(){
    Complex c1, c2;

    // Input two complex numbers
    cout << "Enter the first Complex number:"   << endl;
    cin >> c1;
    cout << "Enter the second Complex number:"   << endl;
    cin >> c2;

    // Perfrom Operations
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    // Output results
    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;
    cout << "Product: " << prod << endl;
    cout << "Quotient: " << quot << endl;

    // Compare complex numbers
    if (c1 == c2){
        cout << "The complex numbers are equal" << endl;
    }
    else{
        cout << "The complex numbers are not equal" << endl;
    }

    return 0;
}