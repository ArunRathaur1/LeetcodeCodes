class Solution {
public:
    int lessthank(vector<int>&nums,int k){
        int left=0;
        int ans=0;
        int l=nums.size();
        map<int,int>m;
        for(int i=0;i<l;i++){
            m[nums[i]]++;
            while(m.size()>k){
                m[nums[left]]--;
                if(m[nums[left]]==0){
                    m.erase(nums[left]);
                }
                left++;
            }
            ans=ans+i-left+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int c1=lessthank(nums,k);
        int c2=lessthank(nums,k-1);
        return c1-c2;
    }
};