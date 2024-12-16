#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
       for(int i=0;i<n;i++){
        int p=abs(nums[i])-1;
            if(nums[p]<0){
                ans.push_back(p+1);
            }
            else{
                nums[p]=-1*(nums[p]);   
            }
       } 
       return ans;
    }
};