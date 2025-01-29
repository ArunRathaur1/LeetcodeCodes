class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        // Edge case: If starting or ending cell is blocked, return -1
        if (grid[0][0] == 1 || grid[row - 1][col - 1] == 1) return -1;

        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        vector<vector<int>> direction = {{-1, 0}, {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, -1}, {1, 1}};
        queue<pair<int, int>> q;
        
        // Start BFS from (0, 0)
        q.push({0, 0});
        distance[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (auto dir : direction) {
                int newx = x + dir[0];
                int newy = y + dir[1];

                // Check boundary conditions and unvisited cells
                if (newx >= 0 && newy >= 0 && newx < row && newy < col && 
                    grid[newx][newy] == 0 && distance[newx][newy] == INT_MAX) {
                    distance[newx][newy] = distance[x][y] + 1;
                    q.push({newx, newy});
                }
            }
        }

        return (distance[row - 1][col - 1] == INT_MAX) ? -1 : distance[row - 1][col - 1];
    }
};
