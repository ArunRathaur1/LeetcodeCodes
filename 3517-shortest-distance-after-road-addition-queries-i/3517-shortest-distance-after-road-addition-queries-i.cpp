class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < n - 1; ++i) {
            adj[i].push_back({i + 1, 1});
        }
        
        vector<int> result;
        
        auto dijkstra = [&]() -> int {
            vector<int> distances(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            
            distances[0] = 0;
            pq.push({0, 0});
            
            while (!pq.empty()) {
                int u = pq.top().second;
                int dist_u = pq.top().first;
                pq.pop();
                
                if (dist_u > distances[u]) continue;
                
                for (const auto& neighbor : adj[u]) {
                    int v = neighbor.first;
                    int weight = neighbor.second;
                    if (distances[u] + weight < distances[v]) {
                        distances[v] = distances[u] + weight;
                        pq.push({distances[v], v});
                    }
                }
            }
            
            return distances[n - 1] == INT_MAX ? -1 : distances[n - 1];
        };
        
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            adj[u].push_back({v, 1});
            result.push_back(dijkstra());
        }
        
        return result; 
    }
};