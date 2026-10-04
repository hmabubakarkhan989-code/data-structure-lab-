#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int rollNumber;
    string studentName;
    string attendanceStatus;
    Student* next;

    Student(int roll, string name, string status)
    {
        rollNumber = roll;
        studentName = name;
        attendanceStatus = status;
        next = NULL;
    }
};

class AttendanceList
{
private:
    Student* head;

public:
    AttendanceList()
    {
        head = NULL;
    }

    void addStudent(int roll, string name, string status)
    {
        Student* newStudent = new Student(roll, name, status);

        if (head == NULL)
        {
            head = newStudent;
        }
        else
        {
            Student* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newStudent;
        }

        cout << "Student added successfully.\n";
    }

    void searchStudent(int roll)
    {
        Student* temp = head;

        while (temp != NULL)
        {
            if (temp->rollNumber == roll)
            {
                cout << "\nStudent Found!\n";
                cout << "Roll Number       : " << temp->rollNumber << endl;
                cout << "Student Name      : " << temp->studentName << endl;
                cout << "Attendance Status : " << temp->attendanceStatus << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "Student not found.\n";
    }

    void deleteStudent(int roll)
    {
        if (head == NULL)
        {
            cout << "Student not found.\n";
            return;
        }

        if (head->rollNumber == roll)
        {
            Student* temp = head;
            head = head->next;

            delete temp;

            cout << "Student deleted successfully.\n";
            return;
        }

        Student* temp = head;

        while (temp->next != NULL)
        {
            if (temp->next->rollNumber == roll)
            {
                Student* deleteStudent = temp->next;

                temp->next = temp->next->next;

                delete deleteStudent;

                cout << "Student deleted successfully.\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Student not found.\n";
    }

    void displayStudents()
    {
        if (head == NULL)
        {
            cout << "No students in the attendance list.\n";
            return;
        }

        Student* temp = head;

        cout << "\n===== Attendance List =====\n";

        while (temp != NULL)
        {
            cout << "Roll Number       : " << temp->rollNumber << endl;
            cout << "Student Name      : " << temp->studentName << endl;
            cout << "Attendance Status : " << temp->attendanceStatus << endl;
            cout << "---------------------------\n";

            temp = temp->next;
        }
    }

    void countPresentStudents()
    {
        Student* temp = head;
        int count = 0;

        while (temp != NULL)
        {
            if (temp->attendanceStatus == "Present" ||
                temp->attendanceStatus == "present")
            {
                count++;
            }

            temp = temp->next;
        }

        cout << "Total students present: " << count << endl;
    }

    // 6. Display final attendance list
    void finalAttendanceList()
    {
        cout << "\n===== Final Attendance List =====\n";

        if (head == NULL)
        {
            cout << "No students in the attendance list.\n";
            return;
        }

        Student* temp = head;

        while (temp != NULL)
        {
            cout << temp->rollNumber << "  "
                 << temp->studentName << "  "
                 << temp->attendanceStatus << endl;

            temp = temp->next;
        }
    }
};

int main()
{
    AttendanceList attendance;

    int choice;
    int roll;
    string name;
    string status;

    do
    {
        cout << "\n===== University Student Attendance System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Search Student\n";
        cout << "3. Delete Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Count Present Students\n";
        cout << "6. Display Final Attendance List\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> roll;

            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter Attendance Status (Present/Absent): ";
            cin >> status;

            attendance.addStudent(roll, name, status);
            break;

        case 2:
            cout << "Enter Roll Number to search: ";
            cin >> roll;

            attendance.searchStudent(roll);
            break;

        case 3:
            cout << "Enter Roll Number to delete: ";
            cin >> roll;

            attendance.deleteStudent(roll);
            break;

        case 4:
            attendance.displayStudents();
            break;

        case 5:
            attendance.countPresentStudents();
            break;

        case 6:
            attendance.finalAttendanceList();
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
