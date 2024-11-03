class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int minsum=INT_MIN;
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            minsum=max(minsum,nums[left]+nums[right]);
            left++;
            right--;
        }
        return minsum;
    }
};