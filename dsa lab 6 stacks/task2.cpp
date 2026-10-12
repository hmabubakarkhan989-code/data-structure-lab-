//2502069 
#include <iostream>
using namespace std;


class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class Stack
{
private:
    Node* top;

public:

    Stack()
    {
        top = NULL;
    }

    void push(int value)
    {
        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;

        cout << value << " pushed into Stack." << endl;
    }


    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow!" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;

        cout << temp->data
             << " popped from Stack." << endl;

        delete temp;
    }


    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "TOP element: "
                 << top->data << endl;
        }
    }


    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty!" << endl;
            return;
        }

        Node* current = top;

        cout << "Stack: ";

        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }


    bool isEmpty()
    {
        return top == NULL;
    }


    ~Stack()
    {
        while (top != NULL)
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack s;


    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);


    s.display();


    s.peek();


    s.pop();

    s.display();

    s.peek();
    cout << "Is stack empty? "
         << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
