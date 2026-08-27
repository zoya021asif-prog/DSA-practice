#include<iostream>
using namespace std;
//print name n times using recursion

    void printname(int i, int n){
        if (i > n){
            return;
        }
        cout << " Zoya " <<endl;
        printname(i + 1, n);
    }
    int main(){
    int n;
    cout << " Enter n:";
    cin >> n;
    printname(1 , n);


 
    return 0;
}