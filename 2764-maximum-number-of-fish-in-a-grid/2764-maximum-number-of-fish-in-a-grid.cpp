class Solution {
public:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(vector<vector<int>>& visited, int row, int col, int i, int j, vector<vector<int>>& grid) {
        // Base case: Check if out of bounds, already visited, or water cell
        if (i < 0 || j < 0 || i >= row || j >= col || visited[i][j] == 1 || grid[i][j] == 0) {
            return 0;
        }
        
        // Mark the current cell as visited
        visited[i][j] = 1;
        
        // Initialize answer with the current cell's fish count
        int ans = grid[i][j];
        
        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            int newx = i + direction[k][0];
            int newy = j + direction[k][1];
            ans += dfs(visited, row, col, newx, newy, grid);
        }
        
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        // Initialize the visited vector
        vector<vector<int>> visited(row, vector<int>(col, 0));
        
        int maxFish = 0;
        
        // Iterate through all cells
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Start DFS if the cell is not visited and is a fish cell
                if (visited[i][j] == 0 && grid[i][j] > 0) {
                    int fishCount = dfs(visited, row, col, i, j, grid);
                    maxFish = max(maxFish, fishCount);
                }
            }
        }
        
        return maxFish;
    }
};
