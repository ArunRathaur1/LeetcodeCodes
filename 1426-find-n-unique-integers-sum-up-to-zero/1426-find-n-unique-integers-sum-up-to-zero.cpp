class Solution {
public:
    vector<int> sumZero(int n) {
      if(n==0)return {0};
      vector<int>ans;
       int tem=1;
        for(int i=0;i<n/2;i++){
            ans.push_back(tem);
            ans.push_back(-1*tem);
            tem++;
        }
      if(n%2==1){
        ans.push_back(0);
      }  
      return ans;
    }
};