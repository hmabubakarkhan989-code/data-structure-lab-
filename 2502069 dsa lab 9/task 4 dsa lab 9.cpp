
#include <iostream>
#include <string>
using namespace std;

class Medicine {
public:
    string name;
    int medicineID;
    string expiryDate;

    Medicine* left;
    Medicine* right;

    Medicine(string n, int id, string date) {
        name = n;
        medicineID = id;
        expiryDate = date;

        left = NULL;
        right = NULL;
    }
};

class MinHeap {
private:
    Medicine* heap[100];
    int size;


    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index]->expiryDate <
                heap[parent]->expiryDate) {

                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }


    void heapifyDown(int index) {
        while (true) {
            int smallest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->expiryDate <
                heap[smallest]->expiryDate) {

                smallest = left;
            }

            if (right < size &&
                heap[right]->expiryDate <
                heap[smallest]->expiryDate) {

                smallest = right;
            }

            if (smallest != index) {
                swap(heap[index], heap[smallest]);
                index = smallest;
            }
            else {
                break;
            }
        }
    }


    void updatePointers() {
        for (int i = 0; i < size; i++) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size)
                heap[i]->left = heap[left];
            else
                heap[i]->left = NULL;

            if (right < size)
                heap[i]->right = heap[right];
            else
                heap[i]->right = NULL;
        }
    }

public:
    MinHeap() {
        size = 0;
    }


    void insert(string name, int id, string date) {
        Medicine* newMedicine =
            new Medicine(name, id, date);

        heap[size] = newMedicine;
        size++;

        heapifyUp(size - 1);
        updatePointers();
    }


    void display() {
        cout << "\nMedicine Heap:\n";

        for (int i = 0; i < size; i++) {
            cout << "Name: " << heap[i]->name
                 << " | ID: " << heap[i]->medicineID
                 << " | Expiry Date: "
                 << heap[i]->expiryDate << endl;
        }
    }


    void nearestExpiry() {
        if (size == 0) {
            cout << "\nNo medicines available.\n";
            return;
        }

        cout << "\nMedicine to be checked first:\n";

        cout << "Name: " << heap[0]->name
             << " | ID: " << heap[0]->medicineID
             << " | Expiry Date: "
             << heap[0]->expiryDate << endl;
    }


    void deleteNearestExpiry() {
        if (size == 0) {
            cout << "\nNo medicine to delete.\n";
            return;
        }

        cout << "\nMedicine removed: "
             << heap[0]->name
             << " | Expiry Date: "
             << heap[0]->expiryDate << endl;

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0) {
            heapifyDown(0);
        }

        updatePointers();
    }


    ~MinHeap() {
        for (int i = 0; i < size; i++) {
            delete heap[i];
        }
    }
};

int main() {
    MinHeap h;

    h.insert("Panadol", 101, "2027-05-10");
    h.insert("Brufen", 102, "2026-12-15");
    h.insert("Augmentin", 103, "2027-02-20");
    h.insert("Calpol", 104, "2026-11-30");
    h.insert("Disprin", 105, "2027-08-25");
    h.insert("Flagyl", 106, "2026-10-20");

    cout << "BEFORE REMOVAL";
    h.display();

    h.nearestExpiry();


    h.deleteNearestExpiry();


    cout << "\nAFTER REMOVAL";
    h.display();

    h.nearestExpiry();

    return 0;
}
