class Solution {
public:
    void combination(vector<int>&nums,int n,int sum,int target,vector<vector<int>>&ans,vector<int>&tem,int index){
        if(sum>target)return;
        if(sum==target){
            ans.push_back(tem);
            return;
        }
        for(int i=index;i<n;i++){
            tem.push_back(nums[i]);
            combination(nums,n,sum+nums[i],target,ans,tem,i);
            tem.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>tem;
        vector<vector<int>>ans;
        int sum=0;
        int n=nums.size();
        combination(nums,n,sum,target,ans,tem,0);
        return ans;
    }
};