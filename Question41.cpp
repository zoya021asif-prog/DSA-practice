#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int dup = n;
    int revnum = 0;
    while(n > 0){
        int lastdigit = n % 10;
        revnum = (revnum * 10) + lastdigit;
        n = n / 10;
    }
    if(dup == revnum){
        cout<<"Palindrome number"<<endl;
    }
    else{
        cout<<"Not a palindrome number"<<endl;
    }

}