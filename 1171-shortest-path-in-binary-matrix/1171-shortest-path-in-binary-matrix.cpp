class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>distance(row,vector<int>(col,INT_MAX));
        vector<vector<int>>direction={{-1,0},{-1,-1},{-1,1},{0,-1,},{0,1},{1,0},{1,-1},{1,1}};
        queue<pair<int,int>>q;
        if(grid[0][0]==0)
         {   
            q.push({0,0});
            distance[0][0]=1;
         }
        while(!q.empty()){
            pair<int,int> t=q.front();
            int x=t.first;
            int y=t.second;
            q.pop();
            for(auto dir:direction){
                int newx=x+dir[0];
                int newy=y+dir[1];
                if(newx>=row||newy>=col||newx<0||newy<0||grid[newx][newy]==1)continue;
                if(distance[newx][newy]>distance[x][y]+1){
                    distance[newx][newy]=distance[x][y]+1;
                    q.push({newx,newy});
                }
            }
        }
        return (distance[row-1][col-1]==INT_MAX?-1:distance[row-1][col-1]);
    }
};