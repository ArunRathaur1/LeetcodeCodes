class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
        }
        int right=0;
        int left=0;
        while(right<n){
            while(left<n&&nums[left]!=0)left++;
            right=left;
            while(right<n&&nums[right]==0)right++;
            if(left<n&& right<n)
            swap(nums[left],nums[right]);
        }
        return nums;
    }
};