#include <iostream>
#include <string>
using namespace std;

class Order
{
public:
    string orderID;
    string customerName;
    string foodItem;
    Order* next;

    Order(string id, string name, string food)
    {
        orderID = id;
        customerName = name;
        foodItem = food;
        next = NULL;
    }
};

class FoodDelivery
{
private:
    Order* head;

public:
    FoodDelivery()
    {
        head = NULL;
    }

    void addOrder(string id, string name, string food)
    {
        Order* newOrder = new Order(id, name, food);

        if (head == NULL)
        {
            head = newOrder;
        }
        else
        {
            Order* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newOrder;
        }

        cout << "Order added successfully.\n";
    }

    void displayOrders()
    {
        if (head == NULL)
        {
            cout << "No pending orders.\n";
            return;
        }

        Order* temp = head;

        cout << "\n===== Pending Orders =====\n";

        while (temp != NULL)
        {
            cout << temp->orderID;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }

    void searchOrder(string id)
    {
        Order* temp = head;

        while (temp != NULL)
        {
            if (temp->orderID == id)
            {
                cout << "\nOrder Found!\n";
                cout << "Order ID      : " << temp->orderID << endl;
                cout << "Customer Name : " << temp->customerName << endl;
                cout << "Food Item     : " << temp->foodItem << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Order not found.\n";
    }

    void removeOrder(string id)
    {
        if (head == NULL)
        {
            cout << "Order not found.\n";
            return;
        }

        if (head->orderID == id)
        {
            Order* temp = head;
            head = head->next;

            delete temp;

            cout << "Order " << id << " delivered and removed.\n";
            return;
        }

        Order* temp = head;

        while (temp->next != NULL)
        {
            if (temp->next->orderID == id)
            {
                Order* deleteOrder = temp->next;

                temp->next = temp->next->next;

                delete deleteOrder;

                cout << "Order " << id << " delivered and removed.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Order not found.\n";
    }

    void addUrgentOrder(string id, string name, string food)
    {
        Order* newOrder = new Order(id, name, food);

        newOrder->next = head;
        head = newOrder;

        cout << "Urgent Order " << id << " received.\n";
    }
    void displayUpdatedOrders()
    {
        cout << "\n===== Updated Pending Orders =====\n";

        if (head == NULL)
        {
            cout << "No pending orders.\n";
            return;
        }

        Order* temp = head;

        while (temp != NULL)
        {
            cout << temp->orderID;

            if (temp->next != NULL)
                cout << " -> ";

            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    FoodDelivery foodDelivery;

    int choice;
    string orderID;
    string customerName;
    string foodItem;

    do
    {
        cout << "\n===== Online Food Delivery System =====\n";
        cout << "1. Add New Order\n";
        cout << "2. Display Pending Orders\n";
        cout << "3. Search Order\n";
        cout << "4. Remove Delivered Order\n";
        cout << "5. Add Urgent Order\n";
        cout << "6. Display Updated Orders\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Order ID: ";
            cin >> orderID;

            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, customerName);

            cout << "Enter Food Item: ";
            getline(cin, foodItem);

            foodDelivery.addOrder(orderID, customerName, foodItem);
            break;

        case 2:
            foodDelivery.displayOrders();
            break;

        case 3:
            cout << "Enter Order ID to search: ";
            cin >> orderID;

            foodDelivery.searchOrder(orderID);
            break;

        case 4:
            cout << "Enter Order ID to remove: ";
            cin >> orderID;

            foodDelivery.removeOrder(orderID);
            break;

        case 5:
            cout << "Enter Urgent Order ID: ";
            cin >> orderID;

            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, customerName);

            cout << "Enter Food Item: ";
            getline(cin, foodItem);

            foodDelivery.addUrgentOrder(orderID, customerName, foodItem);
            break;

        case 6:
            foodDelivery.displayUpdatedOrders();
            break;

        case 7:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
