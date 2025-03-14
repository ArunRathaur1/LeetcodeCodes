class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero=0;
        int left=0;
        int l=nums.size();
        int ans=0;
        for(int i=0;i<l;i++){
            if(nums[i]==0)zero++;
            while(zero>k){
                if(nums[left]==0)zero--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};