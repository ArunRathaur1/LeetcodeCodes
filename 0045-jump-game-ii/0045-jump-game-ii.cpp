class Solution {
public:
    pair<int,bool> jumping(vector<int>& nums,int index , int size,vector<int>&dp){
        if(index==size-1)return {0,true};
        if(index>=size)return {-1,false};
        if(dp[index]!=-1)return {dp[index],true};
        int minjumps=INT_MAX;
        for(int j=1;j<=nums[index];j++){
            pair<int,bool>p=jumping(nums,index+j,size,dp);
            if(p.second==true)
                minjumps=min(minjumps,1+p.first);
        }
        if(minjumps==INT_MAX){
            return {1,false};
        }
        dp[index]=minjumps;
        return {minjumps,true};
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return jumping(nums,0,nums.size(),dp).first;
    }
};