class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
      vector<int>ar;
      int row=grid.size();
      int col=grid[0].size();
      for(int i=0;i<row;i++)
      {
        for(int j=0;j<col;j++){
            ar.push_back(grid[i][j]);
        }
      }
      sort(ar.begin(),ar.end());
      int n=ar.size();
      int p=ar[n/2];
      int count=0;
      for(int i=0;i<n;i++){
        if(abs(ar[i]-p)%x!=0)return -1;
        count=count+abs(ar[i]-p)/x;
      }  
      return count;
    }
};