class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int node, unordered_set<int>& st,vector<bool>& visited) {
        if (st.find(node) != st.end())
            return true;
        if (visited[node] == true)
            return false;
        visited[node] = true;
        if (graph[node].size() == 0) {
            st.insert(node);
            return true;
        }
        for (auto i : graph[node]) {
            bool x = dfs(graph, i, st, visited);
            if (x == false)
                return false;
        }
        st.insert(node);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int s = graph.size();
        unordered_set<int> st;
        vector<int> ar;
        vector<bool> visited(s, false);
        for (int i = 0; i < s; i++) {
            if (visited[i] == false) {
                bool x = dfs(graph, i, st, visited);
                if(x==true)ar.push_back(i);
            }
            else if(st.find(i)!=st.end())ar.push_back(i);
        }
        return ar;
    }
};