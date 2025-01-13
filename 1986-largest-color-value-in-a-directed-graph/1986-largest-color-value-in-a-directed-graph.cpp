class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> inDegree(n, 0);

        // Build adjacency list and in-degree array
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            inDegree[edge[1]]++;
        }

        // Topological Sort using Kahn's Algorithm
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        vector<vector<int>> dp(n, vector<int>(26, 0));
        int nodesProcessed = 0;
        int maxColorValue = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            nodesProcessed++;

            // Increment color count for the current node
            dp[node][colors[node] - 'a']++;

            // Update the maximum color value seen so far
            maxColorValue = max(maxColorValue, *max_element(dp[node].begin(), dp[node].end()));

            // Propagate the values to neighbors
            for (int neighbor : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    dp[neighbor][c] = max(dp[neighbor][c], dp[node][c]);
                }

                // Decrease in-degree and add to queue if it becomes 0
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If there are unprocessed nodes, there's a cycle
        return (nodesProcessed == n) ? maxColorValue : -1;
    }
};
