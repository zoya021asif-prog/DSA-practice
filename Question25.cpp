#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
     int dup = n;
    int revnum = 0;
    while(n > 0){
        int ld = n % 10;
        revnum = (revnum*10) + ld;
        n = n / 10;
    }
    cout<<revnum;
    //if(dup == revnum)
    //   cout<<"true";
    //else cout <<"false";
    //return 0;
}