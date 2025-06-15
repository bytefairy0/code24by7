#include <iostream>
using namespace std;

template <class T>
class Stack {
    private:
        T *arr; // dynamic array of stack elements
        int top; // index of top element in stack
        int capacity; // max size of stack
    
    public:
        // Constructor
        Stack(int size){
            capacity = size;
            arr = new T[capacity];
            top = -1;
        }
        
        // Destructor
        ~Stack(){
            delete[] arr;
        }
        
        // Push adds an item to the top of the stack
        void Push(T item){
            if (top >= capacity - 1){
                cout << "Stack overflow" << endl;
                return;
            }
            arr[++top] = item;
        }

        // Pop removes the top element from the stack
        T pop(){
            if (top < 0){
                cout << "Stack underflow" << endl;
                return -1; 
            }
            return arr[top--];
        }

        // Peek returns the top element of the stack without removing it
        T peek(){
            if (top < 0){
                cout << "Stack is empty" << endl;
                return -1; 
            }
            return arr[top];
        }

        // Check if the stack is empty
        bool isEmpty(){
            return top < 0;
        }

        // Check if the stack is full
        bool isFull(){
            return top >= capacity - 1;
        }
};


int main(){
    // Stack of integers
    Stack<int> s(5);
    s.Push(10);
    s.Push(20);
    s.Push(30);
    cout << "Top element: " << s.peek() << endl;
    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element after pop: " << s.peek() << endl;

    // Stack of characters
    Stack<char> c(5);
    c.Push('A');
    c.Push('B');
    c.Push('C');
    cout << "Top character: " << c.peek() << endl;
    cout << "Popped character: " << c.pop() << endl;
    cout << "Top character after pop: " << c.peek() << endl;

    // You can also:
    // Stack<float>, Stack<string>, etc.

}
