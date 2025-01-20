class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<int>frqrow(row,0);
        vector<int>frqcol(col,0);
        unordered_map<int,pair<int,int>>m;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                m[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<row*col;i++){
            pair<int,int>index=m[arr[i]];
            int r=index.first;
            int c=index.second;
            frqrow[r]++;
            frqcol[c]++;
            if(frqrow[r]==col){
              return i;
            }
            if(frqcol[c]==row){
               return i;
            }
        }
        return -1;
    }
};