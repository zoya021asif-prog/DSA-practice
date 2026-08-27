#include<iostream>
using namespace std;
void printNumbers(int i){
    if(i < 1){
        return;
    }
    printNumbers(i - 1);
    cout<< i <<endl;
}
int main(){
    int n;
    cout << "Enter n:";
    cin >> n;
    printNumbers(n);
    return 0;
}