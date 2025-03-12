class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int point=0;
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)/2;
            if(nums[mid]<0){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        int left1=0;
        int right1=nums.size()-1;
        while(left1<=right1){
            int mid=(left1+right1)/2;
            if(nums[mid]<=0){
                left1=mid+1;
            }
            else{
                right1=mid-1;
            }
        }
        int neg=left;
        int pos=nums.size()-left1;
       return  max(neg,pos);
    }
};