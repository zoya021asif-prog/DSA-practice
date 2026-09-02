#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int dup = n;
    int sum = 0;
    while(n > 0){
        int lastdigit = n % 10;
        sum = sum + ( lastdigit * lastdigit * lastdigit); 
        n = n / 10;
    }
    if(dup == sum){
        cout<<"Armstrong number"<<endl;
    }
    else{
        cout<<"Not an Armstrong number"<<endl;
    }
    return 0;
}