class Solution {
public:
    pair<int,bool> lowerboundd(vector<vector<int>>&matrix,int target,int row,int col){
        int left=0;
        int right=row-1;
        int ans=-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[mid][col-1]<target){
                ans=mid;
                left=mid+1;
            }
            else if(matrix[mid][col-1]>target){
                right=mid-1;
            }
            else{
                ans=mid;
                return {mid,true};
            }
        }
        return {ans,false};
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        pair<int,bool> rowlowerbound=lowerboundd(matrix,target,row,col);
        if(rowlowerbound.second==true)return true;
        if(rowlowerbound.first==row-1)return false;
        int nextrow=rowlowerbound.first+1;
        int left=0;int right=col-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[nextrow][mid]>target){
                right=mid-1;
            }
            else if(matrix[nextrow][mid]<target){
                left=mid+1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};