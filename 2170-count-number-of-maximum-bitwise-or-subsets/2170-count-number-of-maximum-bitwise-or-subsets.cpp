class Solution {
public:
    int countallcombination(vector<int>&nums,int value,int currvalue,int index,int n,vector<vector<int>>&dp){
        if(index==n and currvalue==value)return 1;
        if(index>=n)return 0;
        if(dp[currvalue][index]!=-1)return dp[currvalue][index];
        int p=currvalue|nums[index];
        int include=countallcombination(nums,value,p,index+1,n,dp);
        int exclude=countallcombination(nums,value,currvalue,index+1,n,dp);
        dp[currvalue][index]=include+exclude;
        return include+exclude;
    }
    int countMaxOrSubsets(vector<int>& nums) {
     int maxvalue=0;
     int n=nums.size();
     for(int i=0;i<n;i++){
        maxvalue=maxvalue|nums[i];
     }  
     vector<vector<int>>dp(maxvalue+1,vector<int>(n+1,-1));
     return countallcombination(nums,maxvalue,0,0,n,dp); 
    }
};