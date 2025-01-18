class Solution {
public:
    vector<vector<int>>direction={{0,1},{1,0},{0,-1},{-1,0}};
    vector<int>nocost={1,3,2,4};
    int minCost(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>currcost(row,vector<int>(col,INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        q.push({0,{0,0}});
        currcost[0][0]=0;
        while(!q.empty()){
            pair<int,pair<int,int>>p=q.top();
            q.pop();
            int cost=p.first;
            int x=p.second.first;
            int y=p.second.second;
            if (cost > currcost[x][y]) continue;
           //check the value of grid[x][y]to whoom it is one
           int index=-1;
            for(auto dir: direction){
                index++;
                int newx=x+dir[0];
                int newy=y+dir[1];
                if(newx>=row||newy>=col||newx<0||newy<0)continue;
                int newcost=grid[x][y]==nocost[index]?cost:cost+1;
                    if(currcost[newx][newy]>newcost){
                    currcost[newx][newy]=newcost;
                    q.push({newcost,{newx,newy}});
                }
            }
        }
        return currcost[row-1][col-1];
    }
};