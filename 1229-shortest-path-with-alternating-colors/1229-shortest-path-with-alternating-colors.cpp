class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        
        // Build adjacency list
        for (auto& edge : redEdges) adj[edge[0]].push_back({edge[1], 0}); // 0 represents red edge
        for (auto& edge : blueEdges) adj[edge[0]].push_back({edge[1], 1}); // 1 represents blue edge
        
        // Distance array: distance[node][0] -> last edge was red, distance[node][1] -> last edge was blue
        vector<vector<int>> distance(n, vector<int>(2, INT_MAX));
        distance[0][0] = distance[0][1] = 0; // Distance to start node is 0 for both colors

        queue<pair<int, int>> q; // {node, last edge color}
        q.push({0, 0});
        q.push({0, 1});

        while (!q.empty()) {
            auto [node, color] = q.front();
            q.pop();
            
            for (auto [neighbor, edgeColor] : adj[node]) {
                if (edgeColor != color && distance[neighbor][edgeColor] == INT_MAX) { // Ensure alternating colors
                    distance[neighbor][edgeColor] = distance[node][color] + 1;
                    q.push({neighbor, edgeColor});
                }
            }
        }

        // Final distance computation
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int minDist = min(distance[i][0], distance[i][1]);
            result[i] = (minDist == INT_MAX) ? -1 : minDist;
        }

        return result;
    }
};
