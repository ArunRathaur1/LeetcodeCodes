class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int col=matrix[0].size()-1;
        int row=0;
        int rowsize=matrix.size();
        while(row<rowsize&& col>=0){
            int tem=matrix[row][col];
            if(tem>target){
                col--;
            }
            else if(tem<target){
                row++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};