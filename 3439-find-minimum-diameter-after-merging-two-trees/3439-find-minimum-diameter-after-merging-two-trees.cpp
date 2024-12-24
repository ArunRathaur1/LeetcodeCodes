#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Adjacency list creation
    map<int, vector<int>> adjfunction(vector<vector<int>>& edges) {
        map<int, vector<int>> m;
        for (auto& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        return m;
    }

    // BFS to calculate the farthest node and distance
    pair<int, int> bfs(map<int, vector<int>>& adj, int start) {
        queue<int> q;
        q.push(start);
        unordered_map<int, int> dist;
        dist[start] = 0;

        int farthest_node = start, max_dist = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : adj[node]) {
                if (dist.find(neighbor) == dist.end()) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);

                    if (dist[neighbor] > max_dist) {
                        max_dist = dist[neighbor];
                        farthest_node = neighbor;
                    }
                }
            }
        }
        return {farthest_node, max_dist};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto m1 = adjfunction(edges1);
        auto m2 = adjfunction(edges2);

        // Compute the diameters using BFS
        auto [farthest1_m1, _diameter1_start] = bfs(m1, 0); // Unique variable names
        auto [farthest2_m1, diameter1] = bfs(m1, farthest1_m1);

        auto [farthest1_m2, _diameter2_start] = bfs(m2, 0); // Unique variable names
        auto [farthest2_m2, diameter2] = bfs(m2, farthest1_m2);

        // Calculate the merged diameter
        int x = 0;
        if (diameter1 % 2 == 0 && diameter2 % 2 == 0) {
            x = diameter1 / 2 + diameter2 / 2 + 1;
        } else if (diameter1 % 2 == 0 || diameter2 % 2 == 0) {
            x = diameter1 / 2 + diameter2 / 2 + 2;
        } else {
            x = diameter1 / 2 + diameter2 / 2 + 3;
        }

        return max({x, diameter1, diameter2});
    }
};
