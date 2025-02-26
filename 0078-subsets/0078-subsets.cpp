class Solution {
public:
    void generate(vector<int>&nums,vector<int>tem,vector<vector<int>>&ans,int index,int n){
        if(index==n){
            ans.push_back(tem);
            return;
        }
        generate(nums,tem,ans,index+1,n);
        tem.push_back(nums[index]);
        generate(nums,tem,ans,index+1,n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tem;
        int index=0;
        int n=nums.size();
        generate(nums,tem,ans,index,n);
        return ans;
    }
};