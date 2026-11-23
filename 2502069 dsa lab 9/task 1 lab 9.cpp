#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int patientID;
    int priority;

    Patient* left;
    Patient* right;

    Patient(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;

        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
private:
    Patient* heap[100];
    int size;

    // Heapify Up
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;

            if (heap[index]->priority >
                heap[parent]->priority) {

                swap(heap[index], heap[parent]);
                index = parent;
            }
            else {
                break;
            }
        }
    }

    // Heapify Down
    void heapifyDown(int index) {
        while (true) {
            int largest = index;

            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size &&
                heap[left]->priority >
                heap[largest]->priority) {

                largest = left;
            }

            if (right < size &&
                heap[right]->priority >
                heap[largest]->priority) {

                largest = right;
            }

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else {
                break;
            }
        }
    }

    // Update left and right pointers
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
    MaxHeap() {
        size = 0;
    }

    // Insert Patient
    void insert(string name, int id, int priority) {
        Patient* newPatient = new Patient(name, id, priority);

        heap[size] = newPatient;
        size++;

        heapifyUp(size - 1);
        updatePointers();
    }

    // Level Order Traversal
    void display() {
        cout << "\nHospital Patient Queue:\n";

        for (int i = 0; i < size; i++) {
            cout << "Name: " << heap[i]->name
                 << " | ID: " << heap[i]->patientID
                 << " | Priority: " << heap[i]->priority
                 << endl;
        }
    }

    // Display Highest Priority Patient
    void highestPriorityPatient() {
        if (size == 0) {
            cout << "\nNo patients available.\n";
            return;
        }

        cout << "\nPatient to be treated first:\n";

        cout << "Name: " << heap[0]->name
             << " | ID: " << heap[0]->patientID
             << " | Priority: " << heap[0]->priority
             << endl;
    }

    // Delete treated patient
    void deleteHighest() {
        if (size == 0) {
            cout << "\nNo patients to delete.\n";
            return;
        }

        cout << "\nPatient treated and removed: "
             << heap[0]->name << endl;

        delete heap[0];

        heap[0] = heap[size - 1];
        size--;

        if (size > 0) {
            heapifyDown(0);
        }

        updatePointers();
    }

    // Destructor
    ~MaxHeap() {
        for (int i = 0; i < size; i++) {
            delete heap[i];
        }
    }
};

int main() {
    MaxHeap h;

    // Inserting six patients
    h.insert("Ali", 101, 3);
    h.insert("Ahmed", 102, 5);
    h.insert("Sara", 103, 2);
    h.insert("Usman", 104, 4);
    h.insert("Ayesha", 105, 1);
    h.insert("Bilal", 106, 6);

    // Display all patients
    cout << "BEFORE TREATMENT";
    h.display();

    // Identify highest priority patient
    h.highestPriorityPatient();

    // Treat and delete highest priority patient
    h.deleteHighest();

    // Display updated heap
    cout << "\nAFTER TREATMENT";
    h.display();

    // Display next patient
    h.highestPriorityPatient();

    return 0;
}
