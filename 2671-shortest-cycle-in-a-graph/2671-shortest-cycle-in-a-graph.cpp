class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        // Build the adjacency list
        vector<vector<int>> adj(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int shortestCycle = INT_MAX;

        // Perform BFS from each node
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1); // Distance from the starting node
            vector<int> parent(n, -1); // Parent node to avoid revisiting the same edge
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (dist[neighbor] == -1) {
                        // First time visiting this node
                        dist[neighbor] = dist[node] + 1;
                        parent[neighbor] = node;
                        q.push(neighbor);
                    } else if (neighbor != parent[node]) {
                        // Cycle detected
                        shortestCycle = min(shortestCycle, dist[node] + dist[neighbor] + 1);
                    }
                }
            }
        }

        return (shortestCycle == INT_MAX) ? -1 : shortestCycle;
    }
};
