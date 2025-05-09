#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float cgpa;
    vector<string> courses;

public:
    Student() {
        name = "";
        rollNumber = 0;
        cgpa = 0.0;
    }

    Student(string n, int r, float c) {
        name = n;
        rollNumber = r;
        cgpa = c;
    }

    void addCourse(string course) {
        courses.push_back(course);
    }

    void updateCGPA(float newCGPA) {
        if (newCGPA >= 0.0 && newCGPA <= 4.0) {
            cgpa = newCGPA;
        } else {
            cout << "Invalid CGPA. It should be between 0.0 and 4.0." << endl;
        }
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "Courses: ";
        for (int i = 0; i < courses.size(); i++) {
            cout << courses[i] << " ";
        }
        cout << endl;
    }

    int getRollNumber() {
        return rollNumber;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void addStudent(Student student) {
        students.push_back(student);
    }

    Student* searchStudent(int rollNumber) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getRollNumber() == rollNumber) {
                return &students[i];
            }
        }
        return nullptr;
    }

    void displayAllStudents() {
        for (int i = 0; i < students.size(); i++) {
            students[i].displayInfo();
            cout << "------------------------" << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;

    Student student1("Alice", 101, 3.5);
    Student student2("Bob", 102, 3.8);

    sms.addStudent(student1);
    sms.addStudent(student2);

    cout << "All Student Records:" << endl;
    sms.displayAllStudents();

    int rollToSearch = 101;
    Student* foundStudent = sms.searchStudent(rollToSearch);
    if (foundStudent != nullptr) {
        cout << "Found Student:" << endl;
        foundStudent->displayInfo();
    } else {
        cout << "Student with roll number " << rollToSearch << " not found." << endl;
    }

    if (foundStudent != nullptr) {
        foundStudent->updateCGPA(3.9);
        cout << "Updated Student Information:" << endl;
        foundStudent->displayInfo();
    }

    return 0;
}
