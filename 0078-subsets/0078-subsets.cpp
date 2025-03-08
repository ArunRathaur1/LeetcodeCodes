class Solution {
public:
    void generate(vector<int>&nums,int index,vector<vector<int>>&ans,vector<int>&tem,int n){
        if(index>=n){
            ans.push_back(tem);
            return;
        }
        generate(nums,index+1,ans,tem,n);
        tem.push_back(nums[index]);
        generate(nums,index+1,ans,tem,n);
        tem.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tem;
        int n=nums.size();
        int index=0;
        generate(nums,index,ans,tem,n);
        return ans;
    }
};