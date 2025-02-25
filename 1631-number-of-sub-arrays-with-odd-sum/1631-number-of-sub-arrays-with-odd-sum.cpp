class Solution {
    const long long p=1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        long long currsum=0;
        long long oddcount=0;
        long long evencount=1;
        long long ans=0;
        for(int i=0;i<n;i++){
            currsum=currsum+arr[i];
            if(currsum%2==0){
                long long x=(ans+oddcount)%p;
                ans=x;
                evencount++;
            }
            else{
                long long x=(ans+evencount)%p;
                ans=x;
                oddcount++;
            }
        }
        int p=ans;
        return p;
    }
};