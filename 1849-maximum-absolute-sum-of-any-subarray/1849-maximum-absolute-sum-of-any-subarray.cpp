class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int maxsum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum=0;
            }
            sum=sum+nums[i];
            maxsum=max(maxsum,sum);
            nums[i]=nums[i]*-1;
        }
        sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum<0){
                sum=0;
            }
            sum=sum+nums[i];
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};