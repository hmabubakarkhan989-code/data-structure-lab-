#include <iostream>
#include <string>
using namespace std;

class Course
{
public:
    string courseCode;
    string courseName;
    int creditHours;
    Course* next;

    Course(string code, string name, int hours)
    {
        courseCode = code;
        courseName = name;
        creditHours = hours;
        next = NULL;
    }
};


class CourseList{
private:
    Course* head;

public:

    CourseList()
    {
        head = NULL;
    }

    void addAtBeginning()
    {
        string code, name;
        int hours;

        cout << "\nEnter Course Code: ";
        cin >> code;

        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Credit Hours: ";
        cin >> hours;

        Course* newCourse = new Course(code, name, hours);

        newCourse->next = head;
        head = newCourse;

        cout << "\nCourse added at beginning successfully.\n";
    }


    // 2. ADD COURSE AT END
    void addAtEnd()
    {
        string code, name;
        int hours;

        cout << "\nEnter Course Code: ";
        cin >> code;

        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Credit Hours: ";
        cin >> hours;

        Course* newCourse = new Course(code, name, hours);

        // If list is empty
        if (head == NULL)
        {
            head = newCourse;
        }
        else
        {
            Course* temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newCourse;
        }

        cout << "\nCourse added at end successfully.\n";
    }

    void searchCourse()
    {
        string code;

        cout << "\nEnter Course Code to search: ";
        cin >> code;

        Course* temp = head;

        while (temp != NULL)
        {
            if (temp->courseCode == code)
            {
                cout << "\n===== Course Found =====\n";
                cout << "Course Code  : " << temp->courseCode << endl;
                cout << "Course Name  : " << temp->courseName << endl;
                cout << "Credit Hours : " << temp->creditHours << endl;

                return;
            }

            temp = temp->next;
        }

        cout << "\nCourse not found.\n";
    }

    void deleteCourse()
    {
        string code;

        cout << "\nEnter Course Code to delete: ";
        cin >> code;

        if (head == NULL)
        {
            cout << "\nCourse not found.\n";
            return;
        }

        if (head->courseCode == code)
        {
            Course* temp = head;

            head = head->next;

            delete temp;

            cout << "\nCourse deleted successfully.\n";

            return;
        }

        Course* temp = head;

        while (temp->next != NULL)
        {
            if (temp->next->courseCode == code)
            {
                Course* deleteCourse = temp->next;

                temp->next = temp->next->next;

                delete deleteCourse;

                cout << "\nCourse deleted successfully.\n";

                return;
            }

            temp = temp->next;
        }

        cout << "\nCourse not found.\n";
    }

    void displayCourses()
    {
        if (head == NULL)
        {
            cout << "\nNo courses available.\n";
            return;
        }

        Course* temp = head;

        cout << "\n===== All Courses =====\n";

        while (temp != NULL)
        {
            cout << "Course Code  : " << temp->courseCode << endl;
            cout << "Course Name  : " << temp->courseName << endl;
            cout << "Credit Hours : " << temp->creditHours << endl;

            cout << "-------------------------\n";

            temp = temp->next;
        }
    }
    void displayCourseCodes()
    {
        if (head == NULL)
        {
            cout << "No courses available.\n";
            return;
        }

        Course* temp = head;

        while (temp != NULL)
        {
            cout << temp->courseCode;

            if (temp->next != NULL)
            {
                cout << " -> ";
            }

            temp = temp->next;
        }

        cout << endl;
    }

    int countCourses()
    {
        int count = 0;

        Course* temp = head;

        while (temp != NULL)
        {
            count++;

            temp = temp->next;
        }

        return count;
    }

    void concatenate(CourseList& other)
    {
        if (other.head == NULL)
        {
            return;
        }
        if (head == NULL)
        {
            head = other.head;

            return;
        }

        Course* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = other.head;
    }
};

int main()
{
    CourseList morningCourses;
    CourseList eveningCourses;

    int choice;


    do
    {
        cout << "\n";
        cout << "==============================================\n";
        cout << "   UNIVERSITY DEPARTMENT COURSE MANAGEMENT\n";
        cout << "==============================================\n";

        cout << "1. Add Course to Morning List at Beginning\n";
        cout << "2. Add Course to Morning List at End\n";
        cout << "3. Search Morning Course\n";
        cout << "4. Delete Morning Course\n";
        cout << "5. Display Morning Courses\n";
        cout << "6. Count Morning Courses\n";

        cout << "\n";

        cout << "7. Add Course to Evening List at Beginning\n";
        cout << "8. Add Course to Evening List at End\n";
        cout << "9. Search Evening Course\n";
        cout << "10. Delete Evening Course\n";
        cout << "11. Display Evening Courses\n";
        cout << "12. Count Evening Courses\n";

        cout << "\n";

        cout << "13. Concatenate Evening List with Morning List\n";
        cout << "14. Display Combined Course List\n";

        cout << "\n";
        cout << "15. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;


        switch (choice)
        {

        case 1:

            cout << "\n--- Add Morning Course at Beginning ---\n";

            morningCourses.addAtBeginning();

            break;


        case 2:

            cout << "\n--- Add Morning Course at End ---\n";

            morningCourses.addAtEnd();

            break;


        case 3:

            cout << "\n--- Search Morning Course ---\n";

            morningCourses.searchCourse();

            break;


        case 4:

            cout << "\n--- Delete Morning Course ---\n";

            morningCourses.deleteCourse();

            break;


        case 5:

            cout << "\n--- Morning Courses ---\n";

            morningCourses.displayCourses();

            break;


        case 6:

            cout << "\nTotal Morning Courses: ";

            cout << morningCourses.countCourses();

            cout << endl;

            break;


        // =========================================
        // EVENING COURSES
        // =========================================

        case 7:

            cout << "\n--- Add Evening Course at Beginning ---\n";

            eveningCourses.addAtBeginning();

            break;


        case 8:

            cout << "\n--- Add Evening Course at End ---\n";

            eveningCourses.addAtEnd();

            break;


        case 9:

            cout << "\n--- Search Evening Course ---\n";

            eveningCourses.searchCourse();

            break;


        case 10:

            cout << "\n--- Delete Evening Course ---\n";

            eveningCourses.deleteCourse();

            break;


        case 11:

            cout << "\n--- Evening Courses ---\n";

            eveningCourses.displayCourses();

            break;


        case 12:

            cout << "\nTotal Evening Courses: ";

            cout << eveningCourses.countCourses();

            cout << endl;

            break;

        case 13:

            morningCourses.concatenate(eveningCourses);

            cout << "\nCourse lists concatenated successfully.\n";

            break;
        case 14:

            cout << "\n===== Combined Course List =====\n";

            morningCourses.displayCourseCodes();

            break;

        case 15:

            cout << "\nProgram ended successfully.\n";

            break;


        default:

            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 15);


    return 0;
}
