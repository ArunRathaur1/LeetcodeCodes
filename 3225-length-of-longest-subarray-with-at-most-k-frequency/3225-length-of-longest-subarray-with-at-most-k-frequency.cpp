class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int maxlength=0;
        map<int,int>currfreq;
        int s=nums.size();
        while(right<s){
            if(currfreq.find(nums[right])==currfreq.end()){
                currfreq[nums[right]]++;
            }
            else{
                while(currfreq[nums[right]]>=k){
                    if(currfreq[nums[left]]!=0){
                        currfreq[nums[left]]--;
                    }
                    left++;
                }
                currfreq[nums[right]]++;
            }
            maxlength=max(maxlength,right-left+1);
            right++;
        }
        maxlength=max(maxlength,right-left);
        return maxlength;
    }
};