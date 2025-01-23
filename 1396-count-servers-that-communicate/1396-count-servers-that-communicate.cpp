class Solution {
public:
    void connected(vector<vector<int>>&grid,int row,int col,int i,int j,int &x){
        if(i<0||j<0||i>=row||j>=col||grid[i][j]==2)return;
        if(grid[i][j]==1){
            grid[i][j]=2;
            x++;
            for(int r=0;r<row;r++){
                if(grid[r][j]==1){
                    connected(grid,row,col,r,j,x);
                }
            }
            for(int c=0;c<col;c++){
                if(grid[i][c]==1){
                    connected(grid,row,col,i,c,x);
                }
            }
        }
    }
    int countServers(vector<vector<int>>& grid) {
        int count=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int x=0;
                    connected(grid,row,col,i,j,x);
                    if(x>=2)
                    count=count+x;
                }
            }
        }
        return count;
    }
};