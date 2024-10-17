class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
      int total=0;
      int s=points.size();
      for(int i=0;i<s-1;i++){
        int p=abs(points[i][0]-points[i+1][0]);
        int l=abs(points[i][1]-points[i+1][1]);
        total+=max(p,l);
      }
      return total;  
    }
};