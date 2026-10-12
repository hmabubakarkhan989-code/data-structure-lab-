#include <iostream>
#include <string>
using namespace std;

class ArrayStack {
private:
    string* arr;
    int top;
    int capacity;

public:
    ArrayStack(int size) {
        capacity = size;
        arr = new string[capacity];
        top = -1;
    }

    ~ArrayStack() {
        delete[] arr;
    }

    void push(string page) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = page;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!\n";
            return;
        }
        top--;
    }

    string peek() {
        if (top == -1) {
            return "Stack is empty";
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Browsing history is empty.\n";
            return;
        }
        cout << "Browser History (TOP to bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "- " << arr[i] << endl;
        }
    }
};

int main() {
    ArrayStack history(10);


    history.push("Google");
    history.push("YouTube");
    history.push("Facebook");
    history.push("GitHub");

    history.display();
    cout << endl;


    cout << "Simulating 'Back' button (POP performed)...\n";
    history.pop();
    cout << endl;


    cout << "Current TOP page: " << history.peek() << endl << endl;


    history.display();

    return 0;
}

