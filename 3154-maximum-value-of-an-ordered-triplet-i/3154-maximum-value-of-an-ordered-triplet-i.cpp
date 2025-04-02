class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int l=nums.size();
        for(int left=0;left<l;left++){
            int right=l-1;
            while(left+1<right){
            long long x=*min_element(nums.begin()+left+1,nums.begin()+right);
                ans=max(ans,1LL*(nums[left]-x)*nums[right]);
                right--;
            }
        }
        return ans;
    }
};