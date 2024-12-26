class Solution {
public:
    int findall(vector<int>&nums,int index,int& target,int& n,int currsum,vector<vector<int>>&dp,int offset){
        if(n==index){
            return (target==currsum)?1:0;
        }
        if(dp[index][currsum+offset]!=-1)return dp[index][currsum+offset];
        int add=findall(nums,index+1,target,n,currsum+nums[index],dp,offset);
        int subtract=findall(nums,index+1,target,n,currsum-nums[index],dp,offset);
        dp[index][currsum+offset]=add+subtract;
        return dp[index][currsum+offset];
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int s=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(s,vector<int>(2*sum+1,-1));
        return findall(nums,0,target,s,0,dp,sum);
    }
};