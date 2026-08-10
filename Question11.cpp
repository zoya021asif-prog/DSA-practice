#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter a number:";
    cin>>n;
    // for(int i = 0; i < n; i++){
    //     for(int k=0; k<n-i-1; k++){
    //         cout<<" ";
    //     }
    //     for(int j = 0; j<2*i+1; j++){
    //         cout<<"*";
    //     }
    //      for(int k=0; k<n-i-1; k++){
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }
    // for (int i = n; i >= 0; i--)
    // {

    //     // Inner loop 1 to print white spaces for each row
    //     for (int j = 2 * (n - i) - 1; j > 0; j--)
    //     {
    //         cout<<" ";
    //     }

    //     // Inner loop 2 to print star (*) character for each row
    //     for (int k =  2 * i + 1; k >0; k--)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }
    for(int i = 0; i < n; i++){
        for(int j = 0; j<2*n-1; j++){
            if(j >= n - (i-1) && j <= n + (i-1)){
                printf("*");
            }
            else{
                printf(" ");
            }
            
        }
        
    }
    return 0;
}