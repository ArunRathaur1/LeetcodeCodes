#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    void dfs(const vector<vector<int>>& adj, int node, vector<set<int>>& ans, int startNode) {
        for (int parent : adj[node]) {
            if (ans[startNode].insert(parent).second) { // Only continue if the parent is newly added
                dfs(adj, parent, ans, startNode); // Recur for the parent
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n); // Adjacency list
        vector<set<int>> ans(n);    // To store ancestors without duplicates

        // Build adjacency list (child -> parent)
        for (const auto& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
        }

        // Perform DFS for each node to find all its ancestors
        for (int i = 0; i < n; ++i) {
            dfs(adj, i, ans, i);
        }

        // Convert set to sorted vector for the result
        vector<vector<int>> result(n);
        for (int i = 0; i < n; ++i) {
            result[i] = vector<int>(ans[i].begin(), ans[i].end());
        }

        return result;
    }
};
