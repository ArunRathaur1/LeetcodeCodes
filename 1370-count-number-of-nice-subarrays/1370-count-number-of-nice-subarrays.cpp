class Solution {
public:
    int lessthank(vector<int>&nums,int k){
        int left=0;
        int ans=0;
        int l=nums.size();
        int count=0;
        for(int i=0;i<l;i++){
            count+=(nums[i]%2==0)?0:1;
            while(count>k){
                count-=(nums[left]%2==0)?0:1;
                left++;
            }
            ans=ans+(i-left+1);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int c1=lessthank(nums,k);
        int c2=lessthank(nums,k-1);
        return c1-c2;
    }
};