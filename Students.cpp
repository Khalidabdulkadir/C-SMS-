#include <iostream>
using namespace std;
#include <vector>
#include <fstream>

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

// update Students
void UpdateStudents(){
    Student updateStudent;
    cout<<"Enter RollNumber of Student to update: ";
    cin>>updateStudent.rollNumber;

    for(int i =0; i <students.size(); i++){
        if(students[i].rollNumber == updateStudent.rollNumber){
            cout<<"Student Found: "<< students[i].name <<endl;

            cout<<"Eneter a new name: ";
            cin>>students[i].name;
            cout<<"Enter New Age";
            cin>>students[i].age;
            cout<<"Enter New Class: ";
            cin>>students[i].Class;

            cout<<"Students Details Updated Succesfully\n";
            return;
        }
    }
    cout<<"Students whith Roll Number: "<<updateStudent.rollNumber << " Not Found !"<<endl;

}

// Save to file
void SafeToFile(){
    Student Safetofile;
    ofstream file("Students.txt");
    for(int i =0; i<students.size(); i++){
        file<< Safetofile.name << ""
        << Safetofile.age<< ""
        << Safetofile.rollNumber <<""
        << Safetofile.Class << endl;
    }
    file.close();
    cout<<"Students Saved succesfully!\n";
}
void LoadFromFile(){
    ifstream file("Students.txt");
    if(!file){
        cout<<"There is No previous students records foud\n";
        return ;
    }

    Student student;
    while (file >>student.name >> student.age >> student.rollNumber >> student.Class)
    {
        /* code */
        students.push_back(student);
    }
    file.close();
    cout<<"students loaded successfully!\n";
}
int main(){
    LoadFromFile();
    int choice;
    while (true){
    cout<<"\n1. Add Student\n2. Display All students\n3. Delete Students\n4. Update Students\n5. Exit\n";
    cout<<"Enter a Choice";
    cin>>choice;
    if(choice == 1){
        addStudent();
    }else if(choice == 2){
        displayAllStudents();
    }else if(choice == 3){
        DeleteStudent();
    }else if(choice ==4){
        UpdateStudents();
    }else if(choice == 5)
    {
        SafeToFile();
        return 0;
    }
    else{
        cout<<"Invalid Choice ! Try Again\n";
    }
    }
    return 0;
}