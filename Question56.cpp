#include<iostream>
using namespace std;
int main(){
    string s;
    cout<<"Enter a string:";
    cin>>s;
    int hash[26] = {0};
    for(int i = 0; i<s.size();i++){
        hash[s[i] - 'a']++;

    }
    int q;
    cout<<"Enter the number of queries:";
    cin>>q;
    while(q--){
        char ch;
        cout<<"Enter the character to fetch frequency:";
        cin>>ch;
        cout<<hash[ch - 'a']<<endl;
    }
    return 0;
}