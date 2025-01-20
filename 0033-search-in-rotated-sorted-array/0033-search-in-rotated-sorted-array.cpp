class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int mid=0;
        while(left<=right){
            mid=(left+right)/2;
            cout<<mid<<endl;
            if(nums[mid]==target)return mid;
            if(nums[mid]>=nums[left]){
                if(nums[left]<=target && nums[mid]>=target){
                    right=mid-1;
                }
                else{
                    left=mid+1;
                }
            }
            else{
                if(nums[right]>=target && nums[mid]<=target){
                    left=mid+1;
                }
                else{
                    right=mid-1;
                }
            }
        }
        return -1;
    }
};