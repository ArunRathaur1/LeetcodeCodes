class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Step 1: Initialize a distance matrix with INF (INT_MAX)
        vector<vector<int>> dist(numCourses, vector<int>(numCourses, INT_MAX));

        // Step 2: Set the distance of self-loops to 0
        for (int i = 0; i < numCourses; ++i) {
            dist[i][i] = 0;
        }

        // Step 3: Populate the matrix with direct edges from prerequisites
        for (auto& prereq : prerequisites) {
            dist[prereq[0]][prereq[1]] = 1; // Weight of each edge is 1
        }

        // Step 4: Floyd-Warshall Algorithm to compute shortest distances
        for (int k = 0; k < numCourses; ++k) {
            for (int i = 0; i < numCourses; ++i) {
                for (int j = 0; j < numCourses; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        // Step 5: Answer the queries
        vector<bool> result;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            // If the shortest distance is not INT_MAX, a path exists
            result.push_back(dist[u][v] != INT_MAX);
        }

        return result;
    }
};