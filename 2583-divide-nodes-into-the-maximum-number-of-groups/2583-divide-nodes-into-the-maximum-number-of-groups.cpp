class DSU {
public:
    vector<int> parent, rank;
    
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);  // Path compression
        }
        return parent[x];
    }
    
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj, int n, vector<int>& color) {
        queue<int> q;
        
        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neighbor : adj[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    int getMaxLayer(int start, vector<vector<int>>& adj, int n) {
        queue<int> q;
        vector<int> dist(n, -1);
        
        q.push(start);
        dist[start] = 0;
        int maxDist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    maxDist = max(maxDist, dist[neighbor]);
                }
            }
        }
        return maxDist + 1;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        DSU dsu(n);

        for (auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1; // Assuming 1-based input
            adj[u].push_back(v);
            adj[v].push_back(u);
            dsu.unite(u, v);
        }

        vector<int> color(n, -1);
        if (!isBipartite(adj, n, color)) return -1;

        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; i++) {
            components[dsu.find(i)].push_back(i);
        }

        int totalCount = 0;
        for (auto& [root, nodes] : components) {
            int maxLayer = 0;
            for (int node : nodes) {
                maxLayer = max(maxLayer, getMaxLayer(node, adj, n));
            }
            totalCount += maxLayer;
        }
        
        return totalCount;
    }
};
