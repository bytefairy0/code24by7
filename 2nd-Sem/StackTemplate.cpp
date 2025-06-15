#include <iostream>
using namespace std;

template <class T>
class Stack{
    private:
        T *stack;
        int top;
        int capacity;
    
    public:
        Stack(int size){
            capacity = size;
            stack = new T[capacity];
            top = -1;
        }

        ~Stack(){
            delete[] stack;
        }

        void push(T item){
            if (top >= capacity - 1){
                cout << "Stack overflow" << endl;
                return;
            }
            stack[++top] = item;
        }

        void pop(){
            if (top < 0){
                cout << "Stack Underflow" << endl;
            }
            stack[top--];
        }
    
        T Top(){
            return stack[top];
        }

        // Operation overloading
        // template <typename U> // template function -> so it can work with anytype
        friend ostream& operator << <T>(ostream& os, const Stack<T>& s);

};

template<typename U>
ostream& operator << (ostream& os, const Stack<U>& s){
    os << "Stack: ";
    for (int i = 0; i <= s.top; i++){
        os << s.stack[i] << " ";
    }
    return os;
}


int main(){
    // Integer PUsh
    Stack<int> intStack(3);
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    cout << intStack << endl;

    // String stack
    Stack<string> strStack(3);
    strStack.push("Hello");
    strStack.push("World");

    cout << strStack << endl;

}

