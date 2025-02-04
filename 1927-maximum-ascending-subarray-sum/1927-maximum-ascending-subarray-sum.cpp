class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int p=INT_MIN;
        int n=nums.size();
        int sum=0;
        int maxsum=0;
        for(int i=0;i<n;i++){
            if(p<nums[i]){
                p=nums[i];
                sum=sum+nums[i];
            }
            else{
                maxsum=max(maxsum,sum);
                 p=nums[i];
                 sum=nums[i];
            }
        }
        maxsum=max(maxsum,sum);
        return maxsum;
    }
};