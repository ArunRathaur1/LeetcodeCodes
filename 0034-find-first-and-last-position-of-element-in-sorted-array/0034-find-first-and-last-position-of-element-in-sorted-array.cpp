class Solution {
public:
    int first(vector<int>&nums,int target){
        int index=-1;
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>target){
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                index=mid;
                right=mid-1;
            }
        }
        return index;
    }
    int last(vector<int>&nums,int target){
        int index=-1;
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]>target){
                right=mid-1;
            }
            else if(nums[mid]<target){
                left=mid+1;
            }
            else{
                index=mid;
                left=mid+1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int f=first(nums,target);
        int s=last(nums,target);
        return {f,s};
    }
};