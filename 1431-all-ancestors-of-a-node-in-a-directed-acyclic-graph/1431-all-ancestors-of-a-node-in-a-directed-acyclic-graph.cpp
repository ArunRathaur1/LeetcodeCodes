class Solution {
public:
    void dfs(map<int,vector<int>>&adj,int node,vector<set<int>>&ans,int node1,vector<bool>&visited){
        if(adj.find(node)==adj.end()||adj[node].size()==0||visited[node])return;
        visited[node]=true;
        for(auto i: adj[node]){
            if(ans[node1].find(i)==ans[node1].end())
            {
                ans[node1].insert(i);
                dfs(adj,i,ans,node1,visited);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<set<int>>ans(n);
        map<int,vector<int>>adj;
        int p=edges.size();
        for(int i=0;i<p;i++){
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int i=0;i<n;i++){
            vector<bool>visited(n,false);
            dfs(adj,i,ans,i,visited);
        }
        vector<vector<int>>ar;
        for(int i=0;i<n;i++){
            vector<int>res=vector<int>(ans[i].begin(),ans[i].end());
            ar.push_back(res);
        }
        return ar;
    }

};