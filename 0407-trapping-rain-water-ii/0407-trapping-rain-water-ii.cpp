class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        int row=heightMap.size();
        int col=heightMap[0].size();
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i==0||i==row-1||j==col-1||j==0){
                    visited[i][j]=true;
                    q.push({heightMap[i][j],{i,j}});
                }
            }
        }
        int totalwater=0;
        vector<vector<int>>direction={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            pair<int,pair<int,int>> x=q.top();
            q.pop();
            int value=x.first;
            int r=x.second.first;
            int c=x.second.second;
            for(int i=0;i<4;i++){
                int newx=r+direction[i][0];
                int newy=c+direction[i][1];
                if(newx<0||newy<0||newx>=row||newy>=col)continue;
                if(visited[newx][newy]==false){
                    visited[newx][newy]=true;
                    if(heightMap[newx][newy]<value){
                        totalwater+=value-heightMap[newx][newy];
                        heightMap[newx][newy]=value;
                    }
                    q.push({heightMap[newx][newy],{newx,newy}});
                }
            }
        }
        return totalwater;

    }
};