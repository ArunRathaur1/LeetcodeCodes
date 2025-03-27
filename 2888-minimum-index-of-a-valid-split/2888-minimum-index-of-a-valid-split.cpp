class Solution {
public:
    int dominenent(vector<int>& nums) {
        int m = nums[0], count = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == m) count++;
            else count--;
            if (count == 0) {
                m = nums[i];
                count = 1;
            }
        }
        return m;
    }

    int frequency(vector<int>& nums, int number) {
        int count = 0;
        for (int num : nums) {
            if (num == number) count++;
        }
        return count;
    }

    int minimumIndex(vector<int>& nums) {
        int number = dominenent(nums);
        int right = frequency(nums, number), left = 0, n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == number) {
                left++;
                right--;
            }
            int leftpart = i + 1;
            int rightpart = n - (i + 1);

            if (2 * left > leftpart && 2 * right > rightpart) return i;
        }
        return -1;
    }
};
