#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    //precompute
    map <int,  int> mpp;
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
    }
    for(auto it : mpp){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
    int q;
    cout<<"Enter the number of queries:";
    cin>>q;
    while(q--){
        int number;
        cout<<"Enter the number to fetch frequency:";
        cin>> number;
        //fetch
        cout<<mpp[number]<<endl;
    }
    return 0;
}