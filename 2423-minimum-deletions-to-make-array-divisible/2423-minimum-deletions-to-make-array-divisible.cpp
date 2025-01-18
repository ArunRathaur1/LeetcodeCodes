class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int g=numsDivide[0];
        long long n=numsDivide.size();
        long long k=nums.size();
        for(long long i=1;i<n;i++){
            g=__gcd(numsDivide[i],g);
        }
        int count=0;
        long long min=INT_MAX;
        for(long long i=0;i<k;i++){
            if(g%nums[i]==0&& min>nums[i]){
                min=nums[i];
            }
        }
        if(min==INT_MAX)return -1;
        for(long long i=0;i<k;i++){
            if(nums[i]<min){
                count++;
            }
        }
        return count;
        
    }
};