class Solution {
public:
    int mincost(vector<int>& days,vector<int>&costs,int index,int& n,vector<int>&dp){
        if(index>=n)return 0;
        if(dp[index]!=-1)return dp[index];
        int case1=mincost(days,costs,index+1,n,dp)+costs[0];


        int nextindex=index;
        int curr=days[index]+7;
        while(nextindex<n&&curr>days[nextindex])nextindex++;
        int case2=mincost(days,costs,nextindex,n,dp)+costs[1];



        int nextid=index;
        int currentvalue=days[index]+30;
        while(nextid<n&&currentvalue>days[nextid])nextid++;

        int case3=mincost(days,costs,nextid,n,dp)+costs[2];

        int x=min(case1,min(case2,case3));
        dp[index]=x;

        return x;
    }
    int tabluation(vector<int>&days,vector<int>&costs){
        int n=days.size();
        vector<int>dp(n+1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int case1=dp[i+1]+costs[0];

            int nextindex=i;
            int curr=days[i]+7;
            while(nextindex<n&&curr>days[nextindex])nextindex++;
            int case2=dp[nextindex]+costs[1];

            int nextid=i;
            int currentvalue=days[i]+30;
            while(nextid<n&&currentvalue>days[nextid])nextid++;
            int case3=dp[nextid]+costs[2];

            int x=min(case1,min(case2,case3));
            dp[i]=x;

        }
        return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int size=days.size();
        vector<int>dp(size+1,-1);
        return tabluation(days,costs);
    }
};