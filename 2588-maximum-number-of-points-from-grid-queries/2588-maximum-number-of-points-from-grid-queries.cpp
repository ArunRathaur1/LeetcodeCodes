class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>ar;
        int qs=queries.size();
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<qs;i++)ar.push({queries[i],i});
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        vector<int>ans(qs,0);
        q.push({grid[0][0],{0,0}});
        int count=0;
        visited[0][0]=true;
        while(!ar.empty()){
            while(!q.empty()&& q.top().first<ar.top().first){
                pair<int,pair<int,int>>x=q.top();
                q.pop();
                int vlaue=x.first;
                int temrow=x.second.first;
                int temcol=x.second.second;
                count++;
                for(auto d:dir){
                    int newx=temrow+d[0];
                    int newy=temcol+d[1];
                    if(newx>=row||newy>=col||newx<0||newy<0||visited[newx][newy])continue;
                    visited[newx][newy]=true;
                    q.push({grid[newx][newy],{newx,newy}});
                }
            }
            ans[ar.top().second]=count;
            ar.pop();
        }
        return ans;
    }
};