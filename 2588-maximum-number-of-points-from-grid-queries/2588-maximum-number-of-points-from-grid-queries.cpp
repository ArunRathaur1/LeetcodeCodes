class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int row = grid.size(), col = grid[0].size();
        vector<pair<int, int>> ar;
        
        for (int i = 0; i < queries.size(); i++) {
            ar.push_back({queries[i], i});
        }

        sort(ar.begin(), ar.end());

        vector<int> ans(queries.size(), 0);
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        // Min-heap (priority queue)
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
        q.push({grid[0][0], {0, 0}});
        visited[0][0] = true;

        int count = 0, index = 0;

        while (index < ar.size()) {
            // Process all reachable cells before answering the query
            while (!q.empty() && q.top().first < ar[index].first) {
                auto [value, coord] = q.top();
                auto [temrow, temcol] = coord;
                q.pop();

                count++;

                for (auto& d : dir) {
                    int newx = temrow + d[0];
                    int newy = temcol + d[1];

                    if (newx >= 0 && newy >= 0 && newx < row && newy < col && !visited[newx][newy]) {
                        visited[newx][newy] = true;
                        q.push({grid[newx][newy], {newx, newy}});
                    }
                }
            }

            ans[ar[index].second] = count;
            index++;
        }

        return ans;
    }
};
