class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        q.push({-1, -1});
        vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        while (!q.empty()) {
            pair<int, int> x = q.front();
            q.pop();
            int r = x.first;
            int c = x.second;
            if (r == -1 && c == -1) {
                count++;
                if (!q.empty()) {
                    q.push({-1, -1});
                }
            } 
            else {
                for (int i = 0; i < 4; i++) {
                    int newx = direction[i][0] + r;
                    int newy = direction[i][1] + c;
                    if (newx >= row || newy >= col || newx < 0 || newy < 0)
                        continue;
                    if (grid[newx][newy] == 1) {
                        grid[newx][newy] = 2;
                        q.push({newx, newy});
                    }
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count-1;
    }
};