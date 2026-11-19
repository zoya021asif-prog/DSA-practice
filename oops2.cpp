#include<iostream>
using namespace std;
class Teacher {
    private:
    double salary;

    public:
    //parameterized
    Teacher(string n, string d, string s, double sal) {
        name = n;
        dept = d;
        subject = s;
        salary = sal;
        
    }
    //copy constructor
    Teacher(Teacher &orgObj) {
        cout<< " i am custom copy constructor " << endl;
        this->name = orgObj.name;
        this->dept = orgObj.dept;
        this->subject = orgObj.subject;
        this->salary = orgObj.salary;
    }
    string name;
    string dept;
    string subject;
    void changedept (string newDept) {
        dept = newDept;
    }
    void getInfo(){
        cout << "Name: " << name << endl;
        cout << "Department: " << dept << endl;
        cout << "Subject: " << subject << endl;
        cout << "Salary: " << salary << endl;
    }

};
int main() {
    Teacher t1("Zoya", "Compputer science", "C++", 50000);
    //t1.getInfo();

    Teacher t2(t1);//custom copy constructor -> invoked
    t2.getInfo();
    return 0;
}