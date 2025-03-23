#include <iostream>
using namespace std;
class Student{
    string name;
    int age;
public:
  void CreateStudnet(){
    cout<<"Eneter Name"<<endl;
    cin>>name;
    cout<<"Eneter age"<<endl;
    cin>>age;
  }

  void Displaystudnets(){
    cout<<"Students name is : \n"<<name <<" Age :\n"<<age<<endl;
  }

};
int main(){
    Student students;
    students.CreateStudnet();
    students.Displaystudnets();
    return 0;
}