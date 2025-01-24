class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
       int left=0;
       int right=col-1;
       while(left<=right){
        int mid=(left+right)/2;
        int index=0;
        for(int i=0;i<row;i++){
            if(mat[i][mid]>mat[index][mid]){
                index=i;
            }
        }
        //mat[index][mid]hieght in that colum
        int leftside=mid-1>=0?mat[index][mid-1]:-1;
        int rightside=mid+1<col?mat[index][mid+1]:-1;
        if(mat[index][mid]>leftside&& mat[index][mid]>rightside){
            return {index,mid};
        }
        else if(mat[index][mid]>leftside){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
       } 
       return {-1,-1};
    }
};