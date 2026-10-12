#include <iostream>
#include <string>
using namespace std;

class OrderNode {
public:
    string orderId;
    OrderNode* next;

    OrderNode(string id) {
        orderId = id;
        next = nullptr;
    }
};

class OrderStack {
private:
    OrderNode* top;

public:
    OrderStack() {
        top = nullptr;
    }

    void push(string id) {
        OrderNode* newNode = new OrderNode(id);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow!\n";
            return;
        }
        OrderNode* temp = top;
        top = top->next;
        delete temp;
    }

    string peek() {
        if (top == nullptr) {
            return "Stack is empty";
        }
        return top->orderId;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "No orders in queue.\n";
            return;
        }
        cout << "Restaurant Orders (TOP to bottom):\n";
        OrderNode* current = top;
        while (current != nullptr) {
            cout << "- " << current->orderId << endl;
            current = current->next;
        }
    }
};

int main() {
    OrderStack restaurantStack;


    restaurantStack.push("ORD-101");
    restaurantStack.push("ORD-102");
    restaurantStack.push("ORD-103");
    restaurantStack.push("ORD-104");


    restaurantStack.display();
    cout << endl;


    cout << "Processing two orders (POP x2)...\n";
    restaurantStack.pop();
    restaurantStack.pop();
    cout << endl;


    cout << "Current TOP order: " << restaurantStack.peek() << endl << endl;


    restaurantStack.display();
    cout << endl;


    if (restaurantStack.isEmpty()) {
        cout << "Status: The Stack is empty.\n";
    } else {
        cout << "Status: The Stack is NOT empty.\n";
    }

    return 0;
}
