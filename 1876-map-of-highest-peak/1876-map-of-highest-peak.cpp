class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row=isWater.size();
        int col=isWater[0].size();
        vector<vector<int>>heights(row,vector<int>(col,INT_MAX));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isWater[i][j]==1){
                    heights[i][j]=0;
                    q.push({0,{i,j}});
                }
            }
        }
        vector<vector<int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
           pair<int,pair<int,int>>x=q.front();
           q.pop();
           int height=x.first;
           int r=x.second.first;
           int c=x.second.second;
           for(int i=0;i<4;i++){
            int newx=r+direction[i][0];
            int newy=c+direction[i][1];
            if(newx<0||newx>=row||newy<0||newy>=col)continue;
            if(height+1<heights[newx][newy]){
                heights[newx][newy]=height+1;
                q.push({height+1,{newx,newy}});
            }
           }
        }
        return heights;
    }
};