class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       int row=matrix.size();
       int col=matrix[0].size();
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0)matrix[i][j]=-19273;
        }
       }
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==-19273){
                for(int k=0;k<row;k++){
                    if(matrix[k][j]!=-19273){
                        matrix[k][j]=0;
                    }
                }
                for(int k=0;k<col;k++){
                    if(matrix[i][k]!=-19273){
                        matrix[i][k]=0;
                    }
                }
            }
        }
       }
       for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==-19273){
                matrix[i][j]=0;
            }
        }
       } 
    }
};