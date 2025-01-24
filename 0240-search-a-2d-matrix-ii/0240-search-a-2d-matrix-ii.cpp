class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size()-1;
        int col=0;
        int colsize=matrix[0].size();
        while(col<colsize&& row>=0){
            int x=matrix[row][col];
            if(x>target){
                row--;
            }
            else if(x<target){
               col++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};