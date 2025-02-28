class Solution {
public:
    void subsests(vector<int>&nums,int index,int n,vector<int>&tem,vector<vector<int>>&ans){
        ans.push_back(tem);
        for(int i=index;i<n;i++){
            if(i>index&& nums[i]==nums[i-1])continue;
            tem.push_back(nums[i]);
            subsests(nums,i+1,n,tem,ans);
            tem.pop_back();
        }
       
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>tem;
        int n=nums.size();
        int index=0;
        sort(nums.begin(),nums.end());
        subsests(nums,index,n,tem,ans);
        return ans;
    }
};