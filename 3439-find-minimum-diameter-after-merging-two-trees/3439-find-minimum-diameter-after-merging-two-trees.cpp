#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Converts edge list to adjacency list
    map<int, vector<int>> adjlist(vector<vector<int>>& edges) {
        map<int, vector<int>> adj;
        int n = edges.size();
        for (int i = 0; i < n; i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return adj;
    }

    // Function to find the farthest node from a given node using BFS
    int findmaxnode(map<int, vector<int>>& adj) {
        if (adj.empty()) return 0;

        queue<int> q;
        map<int, bool> visited;
        int start = adj.begin()->first;  // Start from any node in the graph
        q.push(start);
        visited[start] = true;

        int node = start;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto i : adj[t]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                    node = i;  // Update the farthest node
                }
            }
        }
        return node;
    }

    // Function to find the diameter of the graph (longest path between two nodes)
    int finddiameter(map<int, vector<int>>& adj) {
        if (adj.empty()) return 0;

        // Step 1: Find the farthest node from any starting node
        int node = findmaxnode(adj);

        // Step 2: Perform BFS from the farthest node found to determine the diameter
        map<int, bool> visited;
        map<int, int> dis;  // Map to store distance from starting node
        queue<int> q;
        q.push(node);
        visited[node] = true;
        dis[node] = 0;

        int maxDis = 0;
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto i : adj[t]) {
                if (!visited[i]) {
                    visited[i] = true;
                    dis[i] = dis[t] + 1;
                    q.push(i);
                    maxDis = max(maxDis, dis[i]);
                }
            }
        }
        return maxDis;
    }

    // Function to compute the minimum diameter after merging two graphs
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        map<int, vector<int>> adj1 = adjlist(edges1);
        map<int, vector<int>> adj2 = adjlist(edges2);

        // Find the diameters of the two graphs
        int d1 = finddiameter(adj1);
        int d2 = finddiameter(adj2);

        // Calculate merged diameter
        int merged_diameter = 0;
        if (d1 % 2 == 0 && d2 % 2 == 0) {
            merged_diameter = d1 / 2 + d2 / 2 + 1;
        } else if (d1 % 2 == 0 || d2 % 2 == 0) {
            merged_diameter = d1 / 2 + d2 / 2 + 2;
        } else {
            merged_diameter = d1 / 2 + d2 / 2 + 3;
        }

        return max({d1, d2, merged_diameter});
    }
};
