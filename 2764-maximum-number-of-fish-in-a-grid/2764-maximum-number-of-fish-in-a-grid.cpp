class Solution {
public:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int dfs(int row, int col, int i, int j, vector<vector<int>>& grid) {
        // Base case: Check if out of bounds, already visited, or water cell
        if (i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0) {
            return 0;
        }
        
        // Mark the current cell as visited
        
        
        // Initialize answer with the current cell's fish count
        int ans = grid[i][j];
        grid[i][j]=0;
        // Explore all 4 directions
        for (int k = 0; k < 4; k++) {
            int newx = i + direction[k][0];
            int newy = j + direction[k][1];
            ans += dfs(row, col, newx, newy, grid);
        }
        
        return ans;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        
        int maxFish = 0;
        
        // Iterate through all cells
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                // Start DFS if the cell is not visited and is a fish cell
                if ( grid[i][j] > 0) {
                    int fishCount = dfs( row, col, i, j, grid);
                    maxFish = max(maxFish, fishCount);
                }
            }
        }
        
        return maxFish;
    }
};
