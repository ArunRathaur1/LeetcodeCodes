class Solution {
public:
    int  maxmove(vector<vector<int>>& grid,int m,int n,int i,int j,vector<vector<int>>& dp){
        if(i>=n||j>=m||i<0||j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxcount=0;
        if(i+1<n&&j+1<m&& grid[i][j]<grid[i+1][j+1]){
            int count=1+maxmove(grid,m,n,i+1,j+1,dp);
            maxcount=max(count,maxcount);
        }
        if(i<n&&j+1<m&& grid[i][j]<grid[i][j+1]){
            int count=1+maxmove(grid,m,n,i,j+1,dp);
            maxcount=max(count,maxcount);
        }
        if(i-1>=0&&j+1<m&& grid[i][j]<grid[i-1][j+1]){
            int count=1+maxmove(grid,m,n,i-1,j+1,dp);
            maxcount=max(count,maxcount);
        }
        dp[i][j]=maxcount;
        return maxcount;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int value=INT_MIN;
        vector<vector<int>>dp(row,vector<int>(col,-1));
        for(int i=0;i<row;i++){
            int v=maxmove(grid,col,row,i,0,dp);
            value=max(value,v);
        }
        return value;
    }
};