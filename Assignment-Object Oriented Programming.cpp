#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollno;
    float cgpa;
    string courses[10];
    int courseCount;

public:
    Student() {
        name = "";
        rollno = 0;
        cgpa = 0.0;
        courseCount = 0;
    }

    Student(string n, int r, float c) {
        name = n;
        rollno = r;
        cgpa = c;
        courseCount = 0;
    }

    Student(const Student &s) {
        name = s.name;
        rollno = s.rollno;
        cgpa = s.cgpa;
        courseCount = s.courseCount;
        for (int i = 0; i < courseCount; i++)
            courses[i] = s.courses[i];
    }

    ~Student() {}

    void addcourse(string course) {
        if (courseCount < 10) {
            courses[courseCount] = course;
            courseCount++;
        }
    }

    void updateCGPA(float newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 10.0)
            cgpa = newCGPA;
        else
            cout << "Invalid CGPA value!" << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << "\nRoll No: " << rollno
             << "\nCGPA: " << cgpa << "\nCourses: ";
        for (int i = 0; i < courseCount; i++)
            cout << courses[i] << " ";
        cout << "\n";
    }

    int getRoll() {
        return rollno;
    }
};

class StudentManagementSystem {
private:
    Student students[100];
    int count;

public:
    StudentManagementSystem() {
        count = 0;
    }

    void addStudent(Student s) {
        if (count < 100) {
            students[count] = s;
            count++;
        }
    }

    void searchStudent(int roll) {
        for (int i = 0; i < count; i++) {
            if (students[i].getRoll() == roll) {
                students[i].displayInfo();
                return;
            }
        }
        cout << "Student with roll " << roll << " not found.\n";
    }

    void displayAllStudents() {
        for (int i = 0; i < count; i++) {
            students[i].displayInfo();
            cout << "-----------------\n";
        }
    }
};

int main() {
    StudentManagementSystem system;
    int n;

    cout << "Enter number of students to add: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int roll;
        float cgpa;
        int courseCount;
        string course;

        cout << "\nEnter name: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter CGPA: ";
        cin >> cgpa;

        Student s(name, roll, cgpa);

        cout << "Enter number of courses: ";
        cin >> courseCount;

        for (int j = 0; j < courseCount; j++) {
            cout << "Enter course " << j + 1 << ": ";
            cin >> course;
            s.addcourse(course);
        }

        system.addStudent(s);
    }

    cout << "\nAll Students:\n";
    system.displayAllStudents();

    int searchRoll;
    cout << "\nEnter roll number to search: ";
    cin >> searchRoll;
    system.searchStudent(searchRoll);

    return 0;
}
