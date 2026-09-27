#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
          for(int i = 0; i < n; i++){
            int j = i;
            while(j > 0 && nums[j - 1] > nums[j]){
                int temp = nums[j - 1];
                nums[j - 1] = nums[j];
                nums[j] = temp;
                j--;
            }
        }
        return nums;

    }
};
int main(){
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    vector<int>nums(n);
    for(int i = 0; i < n; i++) cin>>nums[i];
    Solution sol;
    vector<int>sorted_nums = sol.insertionSort(nums);
    for(int i = 0; i < n; i++) cout<<sorted_nums[i]<<" ";
    return 0;
}