class Solution {
public:
    bool dfs(vector<vector<int>>&adj,int node,unordered_set<int>&st,vector<bool>&visited){
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
        unordered_set<int>st;
        int s=graph.size();
        vector<bool>visited(s,false);
        for(int i=0;i<s;i++){
            if(visited[i]==false){
                bool x=dfs(graph,i,st,visited);
            }
        }
        vector<int>ar;
        for(auto i: st){
            ar.push_back(i);
        }
        sort(ar.begin(),ar.end());
        return ar;
    }
};