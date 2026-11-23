#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    string name;
    int rollNo;
    int marks;
    Student* left;
    Student* right;
    Student(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = NULL;
        right = NULL;
    }
};
class MaxHeap {
private:
    Student* heap[100];
    int size;
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index]->marks > heap[parent]->marks) {
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
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            if (left < size &&
                heap[left]->marks > heap[largest]->marks) {
                largest = left;
            }
            if (right < size &&
                heap[right]->marks > heap[largest]->marks) {
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
    void insert(string name, int rollNo, int marks) {
        Student* newStudent = new Student(name, rollNo, marks);

        heap[size] = newStudent;
        size++;
        heapifyUp(size - 1);
        updatePointers();
    }
    void display() {
        cout << "\nHeap (Level Order Traversal):\n";

        for (int i = 0; i < size; i++) {
            cout << heap[i]->name
                 << " | Roll No: " << heap[i]->rollNo
                 << " | Marks: " << heap[i]->marks << endl;
        }
    }
    void deleteHighest() {
        if (size == 0) {
            cout << "\nHeap is empty!";
            return;
        }
        cout << "\nDeleted Student: "
             << heap[0]->name
             << " | Marks: " << heap[0]->marks << endl;

        delete heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0) {
            heapifyDown(0);
        }
        updatePointers();
    }
};
int main() {
    MaxHeap h;
    h.insert("Ali", 101, 85);
    h.insert("Ahmed", 102, 95);
    h.insert("Sara", 103, 75);
    h.insert("Usman", 104, 90);
    h.insert("Ayesha", 105, 80);
    h.insert("Bilal", 106, 70);
    cout << "BEFORE DELETION";
    h.display();
    h.deleteHighest();
    cout << "\nAFTER DELETION";
    h.display();
    return 0;
}
