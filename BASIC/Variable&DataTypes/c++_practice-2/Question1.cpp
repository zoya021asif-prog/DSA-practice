#include<iostream>
using namespace std;

int main(){
    int num;
     cout<<"Enter a number:"<<endl;
    cin>>num;
    
    if(num > 0 ){
        cout<<"The Number is positive"<<num<<endl;

    }
    else if(num < 0){
        cout<<"The Number is negative"<<num<<endl;
    }
    else{
        cout<<"The Number is zero"<<num<<endl;
    }
    return 0;
}