class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l=nums.size();
        vector<int>ans;
        deque<int>next;
        for(int i=0;i<k;i++){
            while(!next.empty()&& nums[next.back()]<nums[i]){
                next.pop_back();
            }
            next.push_back(i);
        }
        for(int i=k;i<l;i++){
            ans.push_back(nums[next.front()]);
            while(!next.empty()&& next.front()<=(i-k)){
                next.pop_front();
            }
            while(!next.empty()&& nums[next.back()]<nums[i]){
                next.pop_back();
            }
            next.push_back(i);
        }
        ans.push_back(nums[next.front()]);
        return ans;
    }
};