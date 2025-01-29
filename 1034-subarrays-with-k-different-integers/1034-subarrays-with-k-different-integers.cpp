class Solution {
public:
    int countsubarray(vector<int>&nums,int k){
        int count=0;
        int size=nums.size();
            map<int,int>m;
            int left=0;
            for(int j=0;j<size;j++){
                m[nums[j]]++;
                while(m.size()>k){
                    m[nums[left]]--;
                    if(m[nums[left]]==0){
                        m.erase(nums[left]);
                    }
                    left++;
                }
                count+=j-left+1;
            }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countsubarray(nums,k)-countsubarray(nums,k-1);
    }
};