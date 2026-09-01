#include<iostream>
using namespace std;
int main(){
    int n;
    int count = 0;
    cout<<"Enter a number:";
    cin>>n;
    while(n > 0){
        int lastdigit = n % 10;
        count = count + 1;
        n = n / 10;
    }
    cout<<"Number of digits:"<<count<<endl;
    return 0;
}