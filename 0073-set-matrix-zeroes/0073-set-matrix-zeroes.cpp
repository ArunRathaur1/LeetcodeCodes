class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        // Flags to check if the first row and first column need to be zeroed
        bool flagRow = false;
        bool flagCol = false;

        // Check if the first column needs to be zeroed
        for (int i = 0; i < row; i++) {
            if (matrix[i][0] == 0) {
                flagCol = true;
                break;
            }
        }

        // Check if the first row needs to be zeroed
        for (int j = 0; j < col; j++) {
            if (matrix[0][j] == 0) {
                flagRow = true;
                break;
            }
        }

        // Use the first row and column as markers
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Zero out cells based on markers in the first row and column
        for (int i = 1; i < row; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < col; j++) {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < col; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < row; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle the first row and first column separately
        if (flagRow) {
            for (int j = 0; j < col; j++) {
                matrix[0][j] = 0;
            }
        }

        if (flagCol) {
            for (int i = 0; i < row; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
