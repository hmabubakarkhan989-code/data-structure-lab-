 //2502069 
#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[5];
    int top;
    int size;

public:

    Stack()
    {
        top = -1;
        size = 5;
    }

    void push(int value)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }


    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "Top element is: "
                 << arr[top] << endl;
        }
    }


    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty!" << endl;
        }
        else
        {
            cout << "Stack elements: ";

            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }


    bool isEmpty()
    {
        return top == -1;
    }


    bool isFull()
    {
        return top == size - 1;
    }
};

int main()
{
    Stack s;


    s.push(10);
    s.push(20);
    s.push(50);
    s.push(70);
    s.push(80);
    s.push(100);

    s.display();
    s.peek();

    s.pop();

    cout << "Is stack empty? "
         << (s.isEmpty() ? "Yes" : "No") << endl;

    cout << "Is stack full? "
         << (s.isFull() ? "Yes" : "No") << endl;

    return 0;
}
