#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int factorial = 1;
    while(n > 0){
        factorial *= n;
        --n;
    }
    cout << "Factorial: " << factorial;
    return 0;
}