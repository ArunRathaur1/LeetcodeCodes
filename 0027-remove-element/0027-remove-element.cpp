class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            if(nums[right]==val){
                right--;
                continue;
            }
            else if(nums[left]==val){
                swap(nums[left],nums[right]);
                left++;
                right--;
            }
            else{
                left++;
            }
        }  
        return right+1;
    }
};