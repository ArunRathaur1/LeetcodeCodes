class Solution {
public:
    bool possible(int mid, vector<int>& nums, int k) {
        int count = 0;
        int prevTaken = -2; 
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= mid) {
                count++;
                i++;
                // prevTaken = i;
            }
            if (count >= k) return true;
        }
        return false;
    }
    
    int minCapability(vector<int>& nums, int k) {
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (possible(mid, nums, k)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
