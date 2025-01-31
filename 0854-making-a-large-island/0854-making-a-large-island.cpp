class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;

        // Assign unique IDs to islands and store their sizes
        vector<vector<int>> islandID(row, vector<int>(col, -1));
        vector<int> islandSize;
        int maxsize = 0;

        // Find all islands using BFS
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!visited[i][j] && grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                    int id = islandSize.size();
                    int size = 0;

                    while (!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        int x = curr.first;
                        int y = curr.second;
                        islandID[x][y] = id;
                        size++;

                        for (auto dir : direction) {
                            int nx = x + dir[0];
                            int ny = y + dir[1];
                            if (nx >= 0 && nx < row && ny >= 0 && ny < col && !visited[nx][ny] && grid[nx][ny] == 1) {
                                visited[nx][ny] = true;
                                q.push({nx, ny});
                            }
                        }
                    }

                    islandSize.push_back(size);
                    maxsize = max(maxsize, size);
                }
            }
        }

        // Check each 0 cell to see if flipping it can connect islands
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 0) {
                    set<int> uniqueIslands;
                    int total = 1; // Start with the flipped cell itself

                    for (auto dir : direction) {
                        int nx = i + dir[0];
                        int ny = j + dir[1];
                        if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 1) {
                            int id = islandID[nx][ny];
                            if (uniqueIslands.find(id) == uniqueIslands.end()) {
                                uniqueIslands.insert(id);
                                total += islandSize[id];
                            }
                        }
                    }

                    maxsize = max(maxsize, total);
                }
            }
        }

        return maxsize;
    }
};