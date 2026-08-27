#include<iostream>
using namespace std;
void printNumbers(int num1, int num2){
    if(num1 > num2){
        return;
    }
    int sum = num1 + num2;
    cout<<"sum of " << num1 << " and " << num2 <<" is : " << sum << endl;
    
}
int main(){
    int n1, n2;
    cout<<"Enter two numbers:";
    cin>>n1>>n2;
    printNumbers(n1, n2);
    return 0;
}
