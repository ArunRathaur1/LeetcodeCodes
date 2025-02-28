class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> red_dist(n, INT_MAX), blue_dist(n, INT_MAX);
        vector<vector<pair<int, char>>> adj(n);

        // Construct adjacency list
        for (auto &edge : redEdges)
            adj[edge[0]].push_back({edge[1], 'r'});
        for (auto &edge : blueEdges)
            adj[edge[0]].push_back({edge[1], 'b'});

        queue<pair<int, char>> q;
        q.push({0, 'r'}); // Start from node 0 with red edge
        q.push({0, 'b'}); // Start from node 0 with blue edge
        red_dist[0] = 0;
        blue_dist[0] = 0;

        while (!q.empty()) {
            auto [node, lastColor] = q.front();
            q.pop();
            int cur_dist = (lastColor == 'r') ? red_dist[node] : blue_dist[node];

            for (auto &[neighbor, edgeColor] : adj[node]) {
                if (lastColor != edgeColor) { // Only traverse alternating colors
                    if (edgeColor == 'r' && red_dist[neighbor] > cur_dist + 1) {
                        red_dist[neighbor] = cur_dist + 1;
                        q.push({neighbor, 'r'});
                    } 
                    else if (edgeColor == 'b' && blue_dist[neighbor] > cur_dist + 1) {
                        blue_dist[neighbor] = cur_dist + 1;
                        q.push({neighbor, 'b'});
                    }
                }
            }
        }

        // Compute final result
        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int minDist = min(red_dist[i], blue_dist[i]);
            result[i] = (minDist == INT_MAX) ? -1 : minDist;
        }
        return result;
    }
};
