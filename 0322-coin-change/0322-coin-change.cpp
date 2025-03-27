class Solution {
public:
    int coinsrequired(vector<int>&coins,int amount,int size,vector<int>&dp){
        if(amount<0)return INT_MAX;
        if(amount==0)return 0;
        if(dp[amount]!=-1)return dp[amount];
        int p=INT_MAX;
        for(int i=0;i<size;i++){
            int m=coinsrequired(coins,amount-coins[i],size,dp);
            if(m!=INT_MAX){
                p=min(p,m+1);
            }
        }
        dp[amount]=p;
        return p;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int s=coins.size();
        int x=coinsrequired(coins,amount,s,dp);
        return x==INT_MAX?-1:x;
    }
};