#include<iostream>
using namespace std;
void printNumbers(int i, int sum){
    if(i < 1){
        cout << sum << endl;
        return;
    }
    printNumbers(i - 1, sum + i);
}
int main(){
    int n;
    cout << " Enter n : ";
    cin >> n;
    printNumbers(n,0);
    return 0;
}