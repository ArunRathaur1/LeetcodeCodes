class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int left=0;
        int size=nums.size();
        int ans=INT_MIN;
        for(int right=0;right<size;right++){
            while(nums[right]-nums[left]>2*k){
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};