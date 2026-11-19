#include<iostream>
#include<string>
using namespace std;
class Teacher {
    private:
    double salary;

    public:
    //Properties
    string name;
    string department;
    string subject;
    
    //Methods/member functions
    void changeDept (string newDept) {
        department = newDept;
    }
    //setter
    void setsalary(double s){
        salary = s;
    }
    //getter
    double getsalary() {
        return salary;
    }
};
int main() {
    Teacher t1;
    t1.name = "Zoya";
    t1.department = "Computer science";
    t1.subject = "C++";
    t1.setsalary(50000);

    cout << "Name:" << t1.name <<endl;
    cout << "Salary:" << t1.getsalary() <<endl;
    return 0;
     
      

}