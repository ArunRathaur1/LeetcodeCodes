class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==1)return 1;
        int left=1;
        int val=nums[0];
        int n=nums.size();
       for(int i=0;i<n;i++){
            if(val<nums[i]){
                val=nums[i];
                swap(nums[i],nums[left]);
                left++;
            }
       }
       return left; 
    }
};