class Solution {
public:
    bool dfs(vector<int>& color, int node, vector<vector<int>>& adj, int parent, int colorValue) {
        if (parent != -1 && color[node] == color[parent]) return false;
        
        color[node] = colorValue;
        
        for (auto i : adj[node]) {
            if (color[i] != -1 && color[i] == color[node]) return false;
            if (color[i] == -1) {
                if (!dfs(color, i, adj, node, 1 - colorValue)) return false;
            }
        }
        return true;
    }

    void dfsnodes(vector<int>& nodes, vector<int>& visited, int node, vector<vector<int>>& adj) {
        visited[node] = true;
        nodes.push_back(node);
        for (auto i : adj[node]) {
            if (!visited[i]) {
                dfsnodes(nodes, visited, i, adj);
            }
        }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> color(n, -1);
        vector<vector<int>> adj(n);  // Correctly initialize adjacency list

        int size = edges.size();
        for (int i = 0; i < size; i++) {
            adj[edges[i][0] - 1].push_back(edges[i][1] - 1);  // Assuming 1-based index
            adj[edges[i][1] - 1].push_back(edges[i][0] - 1);
        }

        int colorValue = 1;
        int parent = -1;
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(color, i, adj, parent, colorValue)) return -1;
            }
        }

        vector<bool> visited(n, false);
        int totalCount = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> nodes;
                vector<int> vis(n, false);
                dfsnodes(nodes, vis, i, adj);

                for (auto j : nodes) {
                    visited[j] = true;
                }

                int maxCount = 0;
                for (auto node : nodes) {
                    int count = 0;
                    queue<int> q;
                    q.push(node);
                    q.push(-1);
                    vector<bool> localVisited(n, false);
                    localVisited[node] = true;

                    while (!q.empty()) {
                        int t = q.front();
                        q.pop();
                        if (t == -1) {
                            count++;
                            if (!q.empty()) q.push(-1);
                        } else {
                            for (auto k : adj[t]) {
                                if (!localVisited[k]) {
                                    q.push(k);
                                    localVisited[k] = true;
                                }
                            }
                        }
                    }
                    maxCount = max(maxCount, count);
                }
                totalCount += maxCount;
            }
        }

        return totalCount;
    }
};
