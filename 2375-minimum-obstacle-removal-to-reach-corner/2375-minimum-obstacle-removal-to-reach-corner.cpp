class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
     vector<pair<int,int>>directions={{0,1},{1,0},{-1,0},{0,-1}};
     vector<vector<int>>dis(row,vector<int>(col,INT_MAX));
     dis[0][0]=grid[0][0];
     q.push({0,{0,0}});
     while(!q.empty()){
        auto[cost,distance]=q.top();
        q.pop();
        if(distance.first==row-1&& distance.second==col-1)return cost;
        for(int i=0;i<4;i++){
            int x=distance.first+directions[i].first;
            int y=distance.second+directions[i].second;
            if(x>=0&& y>=0&& y<col&& x<row){
                if(cost+grid[x][y]<dis[x][y]){
                    dis[x][y]=cost+grid[x][y];
                    q.push({dis[x][y],{x,y}});
                }
            }
        }
     }
     return -1;
    }
};