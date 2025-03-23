class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> q;
        vector<vector<pair<int,int>>> adj(n);
        const int mod = 1e9 + 7;

        for(const auto& road : roads) {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }

        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0] = 1;
        distance[0] = 0;
        q.emplace(0, 0);

        while (!q.empty()) {
            auto [weight, node] = q.top();
            q.pop();

            // Avoid unnecessary processing
            if (weight > distance[node]) continue;

            for (auto& [neighbor, edgeWeight] : adj[node]) {
                long long newDist = distance[node] + edgeWeight;

                if (newDist == distance[neighbor]) {
                    ways[neighbor] = (ways[neighbor] + ways[node]) % mod;
                }
                else if (newDist < distance[neighbor]) {
                    distance[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    q.emplace(newDist, neighbor);
                }
            }
        }
        return ways[n - 1];
    }
};
