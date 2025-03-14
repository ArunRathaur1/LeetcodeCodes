class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero=0;
        int one=0;
        int left=0;
        int l=nums.size();
        int ans=0;
        for(int i=0;i<l;i++){
            if(nums[i]==0)zero++;
            if(nums[i]==1)one++;
            while(zero>k){
                if(nums[left]==0)zero--;
                else if(nums[left]==1)one--;
                left++;
            }
            ans=max(ans,one+zero);
        }
        return ans;
    }
};