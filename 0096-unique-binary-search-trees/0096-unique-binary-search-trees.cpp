class Solution {
public:
    
    long long int numTrees(int n) {
      //2nCn
       vector<int>ans(n+1,1);
       ans[0]=1;
       ans[1]=1;
       for(int i=1;i<=n;i++){
        int sum=0;
             for(int j=1;j<=i;j++){
                int left=j-1;
                int right=i-j;
                sum=sum+ans[left]*ans[right];
            }
            ans[i]=sum;
       }
        return ans[n];
      }
};