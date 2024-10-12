class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;

        for (int num : nums) {
            // If the number is even, set ans[i] = -1
            if (num % 2 == 0) {
                ans.push_back(-1);
            } else {
                // Try to find the smallest x such that x OR (x + 1) == num
                bool found = false;
                for (int x = 1; x <= num; ++x) {
                    if ((x | (x + 1)) == num) {
                        ans.push_back(x);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    ans.push_back(-1);
                }
            }
        }

        return ans;
    }
};
