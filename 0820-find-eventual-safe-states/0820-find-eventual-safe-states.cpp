class Solution {
public:
    bool dfs(map<int,vector<int>>&adj,int node,set<int>&st,vector<bool>&visited){
        if(st.find(node)!=st.end())return true;
        if(visited[node]==true)return false;
        visited[node]=true;
        if(adj[node].size()==0){
            st.insert(node);
            return true;
        }
        bool p=true;
        for(auto i: adj[node]){
            bool x=dfs(adj,i,st,visited);
            p=p&x;
        }
       if(p==true){
        st.insert(node);
        return true;
       }
       return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        set<int>st;
        map<int,vector<int>>m;
        int s=graph.size();
        vector<bool>visited(s,false);
        for(int i=0;i<s;i++){
            for(auto j: graph[i]){
                m[i].push_back(j);
            }
        }
        for(int i=0;i<s;i++){
            if(visited[i]==false){
                bool x=dfs(m,i,st,visited);
            }
        }
        vector<int>ar;
        for(auto i: st){
            ar.push_back(i);
        }
        return ar;
    }
};