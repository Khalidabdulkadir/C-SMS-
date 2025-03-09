#include <iostream>
using namespace std;

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
const int MAX_STUDENTS = 100;  // Maximum number of students
Student students[MAX_STUDENTS];
int studetCount = 0;
void addStudent(){
    if(studetCount < MAX_STUDENTS){
        students[studetCount].CreateStudent();
        studetCount ++;
    }else{
        cout << "Student list is full!" << endl;
    }
}

// Display Students
void displayAllStudents(){
    if(studetCount ==0){
        cout<<"There is No studens Stored !"<<endl;
    }
    for(int i =0; i< studetCount; i ++){
        students[i].DisplayStudents();
        cout << "---------------------" << endl;
    }
}

int main(){
    addStudent();
    displayAllStudents();
    return 0;
}