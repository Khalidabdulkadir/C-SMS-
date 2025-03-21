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
        cin.ignore();
        getline(cin, name);

        cout<<"Enter Student Age"<<endl;
        cin>>age;

        cout<<"Enter Student RollNumber"<<endl;
        cin>>rollNumber;

        cout<<"Enter Student Class"<<endl;
        cin>>Class;
    }

    void DisplayStudents() {
        // cout << "Student Name: .\n" << name << "\n student age: \n"<< age <<
        // "\n Student Roll Number: \n" << rollNumber <<"\n Student Class: \n"<<endl;

        cout << ", Name: " << name << ", Roll Number: " << rollNumber 
             << ", Age: " << age << ", Marks: " <<endl;
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
            // Ask for confirmation
            char confirm;
            cout<<"are you sure you want to delete the user !"<<endl;
            cin>>confirm;
            if(confirm = "y" || "Y" ){
                students.erase(students.begin() + i);
                cout<<"Student Deleted Succesfully!\n";
            }else{
                cout<<"deletion cancelled. \n";
            }
            return ;
        }
    }
    cout << "Student with Roll Number " << deleteStudent.rollNumber << " not found!" << endl;
}

int main(){
    int choice;
    while (true){
    cout<<"\n1. Add Student\n2. Display All students\n3. Delete Students\n4. Exit\n";
    cout<<"Enter a Choice";
    cin>>choice;
    if(choice == 1){
        addStudent();
    }else if(choice == 2){
        displayAllStudents();
    }else if(choice == 3){
        DeleteStudent();
    }else{
        cout<<"Invalid Choice ! Try Again\n";
    }
    }
    return 0;
}