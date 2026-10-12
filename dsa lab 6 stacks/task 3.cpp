#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string requestId;
    Node* next;

    Node(string id) {
        requestId = id;
        next = nullptr;
    }
};

class LinkedListStack {
private:
    Node* top;

public:
    LinkedListStack() {
        top = nullptr;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    string peek() {
        if (top == nullptr) {
            return "Stack is empty";
        }
        return top->requestId;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "No emergency requests.\n";
            return;
        }
        cout << "Patient Requests (TOP to bottom):\n";
        Node* current = top;
        while (current != nullptr) {
            cout << "- " << current->requestId << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedListStack hospitalStack;

    // 1. Push patient request IDs
    hospitalStack.push("P101");
    hospitalStack.push("P102");
    hospitalStack.push("P103");
    hospitalStack.push("P104");


    hospitalStack.display();
    cout << endl;


    cout << "Handling latest emergency request (POP performed)...\n";
    hospitalStack.pop();
    cout << endl;


    cout << "New TOP request: " << hospitalStack.peek() << endl << endl;


    hospitalStack.display();

    return 0;
}
