class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        vector<pair<int,int>>ar;
        int qs=queries.size();
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<qs;i++)ar.push_back({queries[i],i});
        sort(ar.begin(),ar.end());
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>q;
        vector<vector<bool>>visited(row,vector<bool>(col,false));
        vector<vector<int>>dir={{-1,0},{0,-1},{1,0},{0,1}};
        vector<int>ans(qs,0);
        q.push({grid[0][0],{0,0}});
        int index=0;
        int count=0;
        visited[0][0]=true;
        while(index<qs){
            while(!q.empty()&& q.top().first<ar[index].first){
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
            ans[ar[index].second]=count;
            index++;
        }
        return ans;
    }
};