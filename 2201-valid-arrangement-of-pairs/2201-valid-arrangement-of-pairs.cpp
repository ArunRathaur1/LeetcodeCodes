class Solution {
public:
    void DFS(map<int,vector<int>>& adj, int start, vector<vector<int>>& ans) {
        while (!adj[start].empty()) {
            int next = adj[start].back();
            adj[start].pop_back(); 
            DFS(adj, next, ans);    
            ans.push_back({start, next});  
        }
    }
    
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int,vector<int>> m;
        map<int,int> in, out;
        
        for (int i = 0; i < pairs.size(); ++i) {
            m[pairs[i][0]].push_back(pairs[i][1]);
            if (in.find(pairs[i][0]) == in.end()) {
                in[pairs[i][0]] = 0;
            }
            if (out.find(pairs[i][1]) == out.end()) {
                out[pairs[i][1]] = 0;
            }
            in[pairs[i][1]]++;
            out[pairs[i][0]]++;
        }

        int start = -1;
        for (auto& [node, outDegree] : out) {
            if (outDegree - in[node] == 1) {
                start = node;
                break;
            }
        }

        if (start == -1) {
            start = out.begin()->first;
        }

        vector<vector<int>> ans;
        DFS(m, start, ans);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
