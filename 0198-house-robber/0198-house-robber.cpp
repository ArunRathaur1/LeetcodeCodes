class Solution {
public:
    int amount(vector<int>&nums,int n,int index,vector<int>&dp){
        if(index>=n)return 0;
        if(dp[index]!=-1)return dp[index];
        int choice1=nums[index]+amount(nums,n,index+2,dp);
        int choice2=amount(nums,n,index+1,dp);
        int p=max(choice1,choice2);
        dp[index]=p;
        return p;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
       int case1=amount(nums,n,0,dp);
       return case1;
    }
};