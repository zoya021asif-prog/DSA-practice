#include<iostream>
using namespace std;
void printname(int i , int n){
    if(i > n){
        return;
    }
    cout<< "Zoya" <<endl;
    printname(i + 1 , n);
}
int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;
    printname(1,n);
    return 0;
}
