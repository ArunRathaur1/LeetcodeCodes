#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to construct adjacency list
    map<int, vector<int>> adjfunction(vector<vector<int>>& edges) {
        map<int, vector<int>> m;
        for (auto& edge : edges) {
            m[edge[0]].push_back(edge[1]);
            m[edge[1]].push_back(edge[0]);
        }
        return m;
    }

    // DFS function to calculate diameter
    int dfs(map<int, vector<int>>& adj, int currnode, vector<bool>& visited, int& diameter) {
        visited[currnode] = true;
        int t1 = 0, t2 = 0;

        for (int neighbor : adj[currnode]) {
            if (!visited[neighbor]) {
                int depth = dfs(adj, neighbor, visited, diameter);
                if (depth > t1) {
                    t2 = t1;
                    t1 = depth;
                } else if (depth > t2) {
                    t2 = depth;
                }
            }
        }

        diameter = max(diameter, t1 + t2);
        return t1 + 1;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto m1 = adjfunction(edges1);
        auto m2 = adjfunction(edges2);

        int diameter1 = 0, diameter2 = 0;

        if (!m1.empty()) {
            vector<bool> visited1(1e5+1, false); // Assuming nodes are between 0 and 1000
            dfs(m1, m1.begin()->first, visited1, diameter1);
        }

        if (!m2.empty()) {
            vector<bool> visited2(1e5+1, false); // Assuming nodes are between 0 and 1000
            dfs(m2, m2.begin()->first, visited2, diameter2);
        }

        int merged_diameter = 0;
        if (diameter1 % 2 == 0 && diameter2 % 2 == 0) {
            merged_diameter = diameter1 / 2 + diameter2 / 2 + 1;
        } else if (diameter1 % 2 == 0 || diameter2 % 2 == 0) {
            merged_diameter = diameter1 / 2 + diameter2 / 2 + 2;
        } else {
            merged_diameter = diameter1 / 2 + diameter2 / 2 + 3;
        }

        return max({merged_diameter, diameter1, diameter2});
    }
};
