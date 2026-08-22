#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int dup = n;
    int sum = 0;
    
    while(n > 0){
       int  ld = n % 10;
        sum = sum + (ld*ld*ld);
        n = n / 10;
        
    }
    if(sum == dup){
        cout<<"Armstong number";
    }
    else{
       cout<< "Not an Armstrong number";
    }
    return 0;
}