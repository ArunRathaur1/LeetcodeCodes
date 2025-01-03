class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long totalsum=0;
        for(int i=0;i<n;i++){
           totalsum=totalsum+nums[i]; 
        }
        int count=0;
        long long currsum=0;
        for(int i=0;i<n-1;i++){
            currsum=currsum+nums[i];
            totalsum=totalsum-nums[i];
            if(currsum>=totalsum){
                count++;
            }
        }
        return count;
    }
};