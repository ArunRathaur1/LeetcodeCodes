class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        int size=nums.size();
        while(left<=right){
            int mid=(left+right)/2;
            int tem=-1;
            if(mid-1>=0&& nums[mid]==nums[mid-1])
            tem=mid-1;
            else if(mid+1<size && nums[mid]==nums[mid+1])
            tem=mid;
            else return nums[mid];
            if(tem%2==0){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return -1;
    }
};