#include <iostream>
#include <string>
using namespace std;

class TextEditorStack {
private:
    string* arr;
    int top;
    int capacity;

public:
    TextEditorStack(int size) {
        capacity = size;
        arr = new string[capacity];
        top = -1;
    }

    ~TextEditorStack() {
        delete[] arr;
    }

    void push(string action) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = action;
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
            cout << "No actions in history.\n";
            return;
        }
        cout << "Editor Actions (TOP to bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "- " << arr[i] << endl;
        }
    }
};

int main() {
    TextEditorStack editor(10);


    editor.push("Type \"Hello\"");
    editor.push("Type \"World\"");
    editor.push("Add \"!\"");
    editor.push("Delete \"!\"");


    editor.display();
    cout << endl;


    cout << "Performing two Undo operations (POP x2)...\n";
    editor.pop();
    editor.pop();
    cout << endl;


    cout << "Current TOP action: " << editor.peek() << endl << endl;


    editor.display();

    return 0;
}

