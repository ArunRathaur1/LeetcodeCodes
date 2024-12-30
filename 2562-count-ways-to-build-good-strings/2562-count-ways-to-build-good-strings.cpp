class Solution {
public:
int value=1e9+7;
    int totalways(int length,int x1,int x2,int cl,vector<int>&dp){
        if(cl==0)return 1;
        if(cl<0)return 0;
        if(dp[cl]!=-1)return dp[cl];
        int case1=totalways(length,x1,x2,cl-x1,dp);
        int case2=totalways(length,x1,x2,cl-x2,dp);
        dp[cl]=(case1%value+case2%value)%value;
        return dp[cl];
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans=0; 
        int p=max(zero,one);
        vector<int>dp(high+zero+one+1,-1);
        for(int i=low;i<=high;i++){
            ans=(ans%value+totalways(i,zero,one,i,dp)%value)%value;
        }
        return ans;
    }
};