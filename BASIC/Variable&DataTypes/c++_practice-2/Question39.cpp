#include<iostream>
using namespace std;
int main(){
    int n, sum = 0;
    cout << "Enter a number:";
    cin >> n;
    while(n > 0){
        int lastdigit = n % 10;
        sum = sum + lastdigit;
        n = n / 10;
    }
    cout << "sum of digits:" << sum << endl;
    return 0;
}