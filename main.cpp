#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
public:
    Student(const string& name, const string& email, const string& faculty) :
        name(name), email(email), faculty(faculty), graduate(false) {}

    string getName() const { return name; }
    string getEmail() const { return email; }
    string getFaculty() const { return faculty; }
    bool isGraduate() const { return graduate; }
    void graduateStudent() { graduate = true; }

private:
    string name;
    string email;
    string faculty;
    bool graduate;
};

class Faculty {
public:
    Faculty(const string& name, const string& field) :
        name(name), field(field) {}

    string getName() const { return name; }
    string getField() const { return field; }

private:
    string name;
    string field;
};

class TUMBoard {
public:
    void createStudent(const string& name, const string& email, const string& faculty_name) {
        students.push_back(Student(name, email, faculty_name));
    }

    void graduateStudent(const string& email) {
        for (auto& student : students) {
            if (student.getEmail() == email) {
                student.graduateStudent();
                return;
            }
        }
        cout << "Student not found." << endl;
    }

    void displayCurrentStudents() {
        for (const auto& student : students) {
            if (!student.isGraduate()) {
                cout << "Name: " << student.getName() << ", Email: " << student.getEmail() << ", Faculty: " << student.getFaculty() << endl;
            }
        }
    }

    void displayGraduates() {
        for (const auto& student : students) {
            if (student.isGraduate()) {
                cout << "Name: " << student.getName() << ", Email: " << student.getEmail() << ", Faculty: " << student.getFaculty() << endl;
            }
        }
    }

    void createFaculty(const string& name, const string& field) {
        faculties.push_back(Faculty(name, field));
    }

    void displayAllFaculties() {
        for (const auto& faculty : faculties) {
            cout << "Name: " << faculty.getName() << ", Field: " << faculty.getField() << endl;
        }
    }

private:
    vector<Student> students;
    vector<Faculty> faculties;
};

int main() {
    TUMBoard tumBoard;

    while (true) {
        cout << "\nTUM Board Operations:" << endl;
        cout << "1. Faculty Operations:" << endl;
        cout << "   1. Create and assign a student to a faculty." << endl;
        cout << "   2. Graduate a student from a faculty." << endl;
        cout << "   3. Display current enrolled students." << endl;
        cout << "   4. Display graduates." << endl;
        cout << "2. General Operations:" << endl;
        cout << "   1. Create a new faculty." << endl;
        cout << "   2. Display University faculties." << endl;
        cout << "   0. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        switch (choice) {
            case 1: {
                int subChoice;
                cout << "Enter sub-choice (1-4): ";
                cin >> subChoice;
                if (subChoice == 1) {
                    string name, email, facultyName;
                    cout << "Enter student name: ";
                    cin >> name;
                    cout << "Enter student email: ";
                    cin >> email;
                    cout << "Enter faculty name: ";
                    cin >> facultyName;
                    tumBoard.createStudent(name, email, facultyName);
                } else if (subChoice == 2) {
                    string email;
                    cout << "Enter student email to graduate: ";
                    cin >> email;
                    tumBoard.graduateStudent(email);
                } else if (subChoice == 3) {
                    tumBoard.displayCurrentStudents();
                } else if (subChoice == 4) {
                    tumBoard.displayGraduates();
                }
                break;
            }
            case 2: {
                int subChoice;
                cout << "Enter sub-choice (1-2): ";
                cin >> subChoice;
                if (subChoice == 1) {
                    string name, field;
                    cout << "Enter faculty name: ";
                    cin >> name;
                    cout << "Enter faculty field: ";
                    cin >> field;
                    tumBoard.createFaculty(name, field);
                } else if (subChoice == 2) {
                    tumBoard.displayAllFaculties();
                }
                break;
            }
        }
    }

    return 0;
}
