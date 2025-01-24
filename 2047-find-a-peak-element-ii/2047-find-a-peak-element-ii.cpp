class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int left=0;
        int right=col-1;
        while(left<=right){
            int mid=(left+right)/2;
            int maxelement=0;
            int index=-1;
            for(int i=0;i<row;i++){
               if(maxelement<mat[i][mid]){
                maxelement=mat[i][mid];
                index=i;
               }
            }
            int x3=mid+1<col?mat[index][mid+1]:-1;//right
            int x4=mid-1>=0?mat[index][mid-1]:-1;//left
            if(mat[index][mid]>x3&& mat[index][mid]>x4)
            {
                return {index,mid};
            }
            else if(mat[index][mid]<x4){
                right=mid-1;
            }
            else{
               left=mid+1;
            }
        }
        return {-1,-1};
    }
};