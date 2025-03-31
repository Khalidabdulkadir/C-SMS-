#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Student {
public:
    string name;
    int age;
    int rollNumber;
    int Class;

    void CreateStudent() {
        cout << "Enter Student Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Student Age: ";
        cin >> age;

        cout << "Enter Student Roll Number: ";
        cin >> rollNumber;

        cout << "Enter Student Class: ";
        cin >> Class;
    }

    void DisplayStudent() const {
        cout << "Name: " << name << ", Roll Number: " << rollNumber
             << ", Age: " << age << ", Class: " << Class << endl;
    }
};

vector<Student> students;

void addStudent() {
    Student newStudent;
    newStudent.CreateStudent();
    students.push_back(newStudent);
}

void displayAllStudents() {
    if (students.empty()) {
        cout << "No students stored!" << endl;
        return;
    }
    for (const Student& student : students) {
        student.DisplayStudent();
    }
}

void DeleteStudent() {
    int rollNumber;
    cout << "Enter Roll Number of Student to Delete: ";
    cin >> rollNumber;

    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].rollNumber == rollNumber) {
            cout << "Deleting Student: " << students[i].name << endl;
            
            char confirm;
            cout << "Are you sure you want to delete this student? (y/n): ";
            cin >> confirm;
            
            if (confirm == 'y' || confirm == 'Y') {
                students.erase(students.begin() + i);
                cout << "Student Deleted Successfully!\n";
            } else {
                cout << "Deletion Cancelled.\n";
            }
            return;
        }
    }
    cout << "Student with Roll Number " << rollNumber << " not found!" << endl;
}

void UpdateStudent() {
    int rollNumber;
    cout << "Enter Roll Number of Student to Update: ";
    cin >> rollNumber;

    for (Student& student : students) {
        if (student.rollNumber == rollNumber) {
            cout << "Student Found: " << student.name << endl;

            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, student.name);
            
            cout << "Enter New Age: ";
            cin >> student.age;
            
            cout << "Enter New Class: ";
            cin >> student.Class;

            cout << "Student Details Updated Successfully!\n";
            return;
        }
    }
    cout << "Student with Roll Number " << rollNumber << " not found!" << endl;
}

// search by name 
void searchByName(){
    string searchname;
    cout<<"Enter Student name to search: ";
    cin.ignore();
    getline(cin, searchname);

    bool found = false;
    for(const Student& student : students){
        if(student.name == searchname){
            student.DisplayStudent();
            found = true;

        }
    }
    if(!found){
        cout << "Student with name '" << searchname << "' not found!\n";
    }
}

void SaveToFile() {
    ofstream file("students.txt");
    if (!file) {
        cout << "Error saving students!" << endl;
        return;
    }

    for (const Student& student : students) {
        file << student.name << " " << student.age << " " << student.rollNumber << " " << student.Class << endl;
    }
    file.close();
    cout << "Students saved successfully!\n";
}

void LoadFromFile() {
    ifstream file("students.txt");
    if (!file) {
        cout << "No previous student records found.\n";
        return;
    }

    Student student;
    while (file >> student.name >> student.age >> student.rollNumber >> student.Class) {
        students.push_back(student);
    }
    file.close();
    cout << "Students loaded successfully!\n";
}

int main() {
    LoadFromFile();
    int choice;
    while (true) {
        cout << "\n1. Add Student\n2. Display All Students\n3. Delete Student\n4. Update Student\n5. search Student by name\n6. Save and Exit\n";
        cout << "Enter a Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: DeleteStudent(); break;
            case 4: UpdateStudent(); break;
            case 5: searchByName(); break;
            case 6: SaveToFile(); return 0;
            default: cout << "Invalid Choice! Try Again.\n";
        }
    }
}
