#include <iostream>
using namespace std;
#include <vector>

class Student{
    public:
    string name;
    int age;
    int rollNumber;
    int Class;

    void CreateStudent(){
        cout<<"Enter Student Name"<<endl;
        cin>>name;

        cout<<"Enter Student Age"<<endl;
        cin>>age;

        cout<<"Enter Student RollNumber"<<endl;
        cin>>rollNumber;

        cout<<"Enter Student Class"<<endl;
        cin>>Class;
    }

    void DisplayStudents() {
        cout << "Student Name: " << name << endl;
        cout << "Student Age: " << age << endl;
        cout << "Student Roll Number: " << rollNumber << endl;
        cout << "Student Class: " << Class << endl; // Add endl here
    }
};

// golobal variables
vector<Student> students;

void addStudent(){
    Student newStudent;
    newStudent.CreateStudent();
    students.push_back(newStudent);
}

// Display Students
void displayAllStudents(){
    if(students.empty()){
        cout << "No students stored!" << endl;
        return;
    }
    for (Student student : students) {
        student.DisplayStudents();
    }
}

// Delete Students
void DeleteStudent(){
    Student deleteStudent;
    cout << "Enter Roll Number of Student to Delete: ";
    cin >> deleteStudent.rollNumber;
    for(int i =0; i < students.size(); i++){
        if(students[i].rollNumber == deleteStudent.rollNumber){
            cout<<"Deleting Student: "<<students[i].name <<endl;
            students.erase(students.begin() + i);
            cout<<"Student Deleted Succesfully!\n";
            return ;
        }
    }
    cout << "Student with Roll Number " << deleteStudent.rollNumber << " not found!" << endl;
}

int main(){
    addStudent();
    displayAllStudents();
    DeleteStudent();
    return 0;
}