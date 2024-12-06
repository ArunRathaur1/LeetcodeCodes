class Solution {
public:
    void dfs(vector<int>& edges, vector<bool>& visited, vector<bool>& inPath, int node, int& count, unordered_map<int, int>& dist) {
        visited[node] = true;
        inPath[node] = true;

        int neighbor = edges[node];
        if (neighbor != -1) {
            if (!visited[neighbor]) {
                dist[neighbor] = dist[node] + 1;
                dfs(edges, visited, inPath, neighbor, count, dist);
            } else if (inPath[neighbor]) {
                // Cycle detected
                count = max(count, dist[node] - dist[neighbor] + 1);
            }
        }

        inPath[node] = false; // Mark the node as no longer in the current DFS path
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<bool> inPath(n, false);
        int count = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                unordered_map<int, int> dist; // New distance map for each DFS
                dist[i] = 0; // Start distance for the current node
                dfs(edges, visited, inPath, i, count, dist);
            }
        }

        return count;
    }
};
