class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        vector<int>prefixsum(n+1,0);
        for(int i=0;i<n;i++){
            prefixsum[i+1]=prefixsum[i]+nums[i];
        }
        //case1 
        int sum=0;
        for(int i=firstLen;i<=n-secondLen;i++){
            int p=prefixsum[i]-prefixsum[i-firstLen];
            for(int j=i+secondLen;j<=n;j++){
                sum=max(sum,p+prefixsum[j]-prefixsum[j-secondLen]);
            }
        }
        //case2
        for(int i=secondLen;i<=n-firstLen;i++){
            int p=prefixsum[i]-prefixsum[i-secondLen];
            for(int j=i+firstLen;j<=n;j++){
                sum=max(sum,p+prefixsum[j]-prefixsum[j-firstLen]);
            }
        }
        return sum;
    }
};