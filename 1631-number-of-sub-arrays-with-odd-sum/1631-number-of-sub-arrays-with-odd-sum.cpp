class Solution {
    const long long p=1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        vector<int>prefix(n+1,0);
        long long oddcount=0;
        long long evencount=1;
        for(int i=0;i<arr.size();i++){
            prefix[i+1]=prefix[i]+arr[i];
        }
        long long ans=0;
        for(int i=1;i<n+1;i++){
            if(prefix[i]%2==0){
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