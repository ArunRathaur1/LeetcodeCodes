class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<vector<pair<int, int>>> ar;
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;

        // Find all islands using BFS with 4-directional checks
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                    vector<pair<int, int>> pairs;
                    while (!q.empty()) {
                        pair<int, int> tem = q.front();
                        q.pop();
                        int x = tem.first;
                        int y = tem.second;
                        pairs.push_back({x, y});
                        for (auto dir : direction) {
                            int newx = x + dir[0];
                            int newy = y + dir[1];
                            if (newx >= 0 && newx < row && newy >= 0 && newy < col && !visited[newx][newy] && grid[newx][newy] == 1) {
                                visited[newx][newy] = true;
                                q.push({newx, newy});
                            }
                        }
                    }
                    ar.push_back(pairs);
                }
            }
        }

        // Handle case where there are no 0s
        bool allOnes = true;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    allOnes = false;
                    break;
                }
            }
            if (!allOnes) break;
        }
        if (allOnes) {
            return row * col;
        }

        // Create islandID matrix
        vector<vector<int>> islandID(row, vector<int>(col, -1));
        for (int i = 0; i < ar.size(); i++) {
            for (auto& p : ar[i]) {
                int x = p.first;
                int y = p.second;
                islandID[x][y] = i;
            }
        }

        int maxsize = 0;
        for (int i = 0; i < ar.size(); i++) {
            maxsize = max(maxsize, (int)ar[i].size());
        }

        // Check each 0 cell
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    set<int> adjacentIslands;
                    for (auto dir : direction) {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 1) {
                            int islandIdx = islandID[ni][nj];
                            if (islandIdx != -1) {
                                adjacentIslands.insert(islandIdx);
                            }
                        }
                    }
                    int current = 1; // the flipped cell
                    for (int idx : adjacentIslands) {
                        current += ar[idx].size();
                    }
                    maxsize = max(maxsize, current);
                }
            }
        }

        return maxsize;
    }
};