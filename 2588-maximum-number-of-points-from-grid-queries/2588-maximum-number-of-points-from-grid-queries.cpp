class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>>ar;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<queries.size();i++){
            ar.push_back({queries[i],i});
        }
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        vector<int>ans(queries.size(),0);
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        sort(ar.begin(),ar.end());
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        int count=0;
        int index=0;
        q.push({grid[0][0],{0,0}});
        visited[0][0]=true;
        while(index<ar.size()){
            while(!q.empty()&& q.top().first<ar[index].first){
                pair<int,pair<int,int>>x=q.top();
                 q.pop();
                int value=x.first;
                int temrow=x.second.first;
                int temcol=x.second.second;
                count++;
                for(auto d:dir){
                    int newx=temrow+d[0];
                    int newy=temcol+d[1];
                    if(newx>=row||newy>=col||newx<0||newy<0||visited[newx][newy]==true)
                    continue;
                    q.push({grid[newx][newy],{newx,newy}});
                    visited[newx][newy]=true;
                }
            }
            ans[ar[index].second]=count;
            index++;
        }
        return ans;
    }
};