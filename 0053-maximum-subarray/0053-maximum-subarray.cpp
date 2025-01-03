class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum=0;
        int maxsum=INT_MIN;
        int k=nums.size();
        for(int i=0;i<k;i++){
            if(currsum<0){
                currsum=0;
            }
            currsum=currsum+nums[i];
            maxsum=max(maxsum,currsum);
        }
        return maxsum;
    }
};