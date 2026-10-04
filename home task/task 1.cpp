#include <iostream>
#include <string>
using namespace std;

class Patient
{
public:
    int patientID;
    string patientName;
    int patientAge;
    Patient* next;

    Patient(int id, string name, int age)
    {
        patientID = id;
        patientName = name;
        patientAge = age;
        next = NULL;
    }
};

class Hospital
{
private:
    Patient* head;

public:
    Hospital()
    {
        head = NULL;
    }

    // 1. Add new patient at the end
    void addPatient(int id, string name, int age)
    {
        Patient* newPatient = new Patient(id, name, age);

        if (head == NULL)
        {
            head = newPatient;
        }
        else
        {
            Patient* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newPatient;
        }

        cout << "Patient added successfully.\n";
    }

    // 2. Add emergency patient at the beginning
    void addEmergencyPatient(int id, string name, int age)
    {
        Patient* newPatient = new Patient(id, name, age);

        newPatient->next = head;
        head = newPatient;

        cout << "Emergency patient added at the beginning.\n";
    }

    // 3. Search patient using Patient ID
    void searchPatient(int id)
    {
        Patient* temp = head;

        while (temp != NULL)
        {
            if (temp->patientID == id)
            {
                cout << "\nPatient Found!\n";
                cout << "Patient ID   : " << temp->patientID << endl;
                cout << "Patient Name : " << temp->patientName << endl;
                cout << "Patient Age  : " << temp->patientAge << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Patient with ID " << id << " does not exist.\n";
    }

    // 4. Remove patient after treatment using Patient ID
    void removePatient(int id)
    {
        if (head == NULL)
        {
            cout << "No patients are waiting.\n";
            return;
        }

        // If first patient needs to be removed
        if (head->patientID == id)
        {
            Patient* temp = head;
            head = head->next;
            delete temp;

            cout << "Patient removed successfully.\n";
            return;
        }

        Patient* temp = head;

        while (temp->next != NULL)
        {
            if (temp->next->patientID == id)
            {
                Patient* deletePatient = temp->next;

                temp->next = temp->next->next;

                delete deletePatient;

                cout << "Patient removed successfully.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Patient with ID " << id << " does not exist.\n";
    }

    // 5. Display all waiting patients
    void displayPatients()
    {
        if (head == NULL)
        {
            cout << "No patients are waiting.\n";
            return;
        }

        Patient* temp = head;

        cout << "\n===== Waiting Patients =====\n";

        while (temp != NULL)
        {
            cout << "Patient ID   : " << temp->patientID << endl;
            cout << "Patient Name : " << temp->patientName << endl;
            cout << "Patient Age  : " << temp->patientAge << endl;
            cout << "----------------------------\n";

            temp = temp->next;
        }
    }
};

int main()
{
    Hospital hospital;

    int choice;
    int id, age;
    string name;

    do
    {
        cout << "\n===== Hospital Emergency Patient Management =====\n";
        cout << "1. Add New Patient\n";
        cout << "2. Add Emergency Patient\n";
        cout << "3. Search Patient\n";
        cout << "4. Remove Patient After Treatment\n";
        cout << "5. Display All Waiting Patients\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Patient Age: ";
            cin >> age;

            hospital.addPatient(id, name, age);
            break;

        case 2:
            cout << "Enter Emergency Patient ID: ";
            cin >> id;

            cout << "Enter Patient Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Patient Age: ";
            cin >> age;

            hospital.addEmergencyPatient(id, name, age);
            break;

        case 3:
            cout << "Enter Patient ID to search: ";
            cin >> id;

            hospital.searchPatient(id);
            break;

        case 4:
            cout << "Enter Patient ID to remove: ";
            cin >> id;

            hospital.removePatient(id);
            break;

        case 5:
            hospital.displayPatients();
            break;

        case 6:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
