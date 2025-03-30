class Solution {
public:
    int sum(vector<int>&nums,int goal){
        int sum=0;
        int l=nums.size();
        int left=0;
        int count=0;
        for(int i=0;i<l;i++){
            sum=sum+nums[i];
            while(left<=i&&sum>goal){
                sum=sum-nums[left];
                left++;
            }
            count=count+i-left+1;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return sum(nums,goal)-sum(nums,goal-1);
    }
};