class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int row=heights.size();
        int col=heights[0].size();
        vector<vector<int>>effort(row,vector<int>(col,INT_MAX));
        effort[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,0}});
        vector<vector<int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()){
            pair<int,pair<int,int>>t=q.top();
            q.pop();
            int e=t.first;
            int x=t.second.first;
            int y=t.second.second;
            for(auto i:direction){
                int newx=x+i[0];
                int newy=y+i[1];
                if(newx>=row||newy>=col||newx<0||newy<0)continue;
                int p=abs(heights[newx][newy]-heights[x][y]);
                int neweffort=max(p,e);
                if(effort[newx][newy]>neweffort){
                    effort[newx][newy]=neweffort;
                    q.push( {effort[newx][newy],{newx,newy}});
                }
            }
        }
        return effort[row-1][col-1];
    }
};