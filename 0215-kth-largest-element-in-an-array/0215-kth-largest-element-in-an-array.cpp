class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        priority_queue<int>q;
        int n=nums.size();
        for(int i=0;i<n;i++){
            q.push(nums[i]);
        }
        while(k!=1){
            k--;
            q.pop();
        }
        return q.top();
    }
};