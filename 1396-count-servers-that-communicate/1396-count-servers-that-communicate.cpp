class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count=0;
        int row=grid.size();
        int col=grid[0].size();
        vector<int>rownumber;
        vector<int>colnumber;
        for(int i=0;i<col;i++){
            int temsum=0;
            for(int j=0;j<row;j++){
                temsum=temsum+grid[j][i];
            }
            rownumber.push_back(temsum);
        }
        for(int i=0;i<row;i++){
            int temsum=0;
            for(int j=0;j<col;j++){
                    temsum=temsum+grid[i][j];
            }
            colnumber.push_back(temsum);
        }
        int total=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if (grid[i][j] == 1 && (rownumber[j] > 1 || colnumber[i] > 1)) {
                    total++;
                }
            }
        }
        return total;
    }
};