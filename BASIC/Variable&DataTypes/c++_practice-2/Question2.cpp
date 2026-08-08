#include<iostream>
using namespace std;

int main(){
    //int num;
    //cout<<"Enter a number:"<<endl;
    //cin>>num;

    // if(num % 2 == 0){
    //     cout<<"The number is even"<<endl;

    // }
    // else if(num % 2 != 0){
    //     cout<<"The number is odd"<<endl;
    // }
    int age;
    cout << "Enter a age:";
    cin >> age;
    if(age < 18){
        cout<<"Not eligible for job";
    }
    else if(age >= 18  && age <= 54){
        cout<<"Eligible for job";

    }
    else if(age >= 55 && age <= 57){
        cout<<"Eliggible for job,but retirement soon";

    }
    else {
        cout<<"Retirement time";
    }

    
    return 0;
}