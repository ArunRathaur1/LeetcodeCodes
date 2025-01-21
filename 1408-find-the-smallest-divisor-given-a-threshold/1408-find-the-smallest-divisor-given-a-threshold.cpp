class Solution {
public:
    bool possible(vector<int>&nums,int threshold,int mid){
        int count=0;
        for(auto i: nums){
            if(i%mid==0){
                count=count+i/mid;
            }
            else{
                count=count+1+i/mid;
            }
        }
        if(count<=threshold){
            return true;
        }
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int right=*max_element(nums.begin(),nums.end());
        int left=1;
        int ans=0;
        while(left<=right){
            int mid=(left+right)/2;
            if(possible(nums,threshold,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
};