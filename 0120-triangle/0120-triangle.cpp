class Solution {
public:
    int minsum(vector<vector<int>>&triangle,int row,int col,int i,int j,vector<vector<int>>&dp){
        if(i>row||j>=col)return INT_MAX;
        if(i==row)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int case1=triangle[i][j]+minsum(triangle,row,col+1,i+1,j,dp);
        int case2=triangle[i][j]+minsum(triangle,row,col+1,i+1,j+1,dp);
        int x=min(case1,case2);
        dp[i][j]=x;
        return x;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int row=triangle.size();
        vector<vector<int>>dp(row,vector<int>(row,-1));
        int col=1;
        return minsum(triangle,row,col,0,0,dp);
    }
};