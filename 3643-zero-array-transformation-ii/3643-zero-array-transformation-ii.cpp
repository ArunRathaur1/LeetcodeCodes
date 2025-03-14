class Solution {
public:
    bool possible(vector<int> nums, vector<vector<int>>& q, int mid) {
        int l = nums.size();
        vector<int> diff(l , 0);
        diff[0]=nums[0];
        for (int i = 1; i < l; i++) {
            diff[i] = nums[i]-nums[i-1];
        }
        for (int i = 0; i < mid; i++) {
            int left = q[i][0];
            int right = q[i][1];
            int value = q[i][2];

            diff[left] -= value;
            if (right + 1 < l) 
            {
                diff[right + 1] += value;
            }
                
        }
        nums[0] = diff[0];
        for (int i = 1; i < l; i++) {
            nums[i] = nums[i - 1] + diff[i];
        }
        for (int i : nums) {
            if (i>0) return false;
        }
        
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int left = 0, right = q.size();  
        int ans = -1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (possible(nums, q, mid)) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
