class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int x1 = 0, x2 = 0;
        int t = nums.size();
        for (int i = 0; i < t; i++) {
            if (x1 == nums[i]) {
                count1++;
            } else if (x2 == nums[i]) {
                count2++;
            } else if (count1 == 0) {
                count1 = 1;
                x1 = nums[i];
            } else if (count2 == 0) {
                count2 = 1;
                x2 = nums[i];
            } else {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < t; i++) {
            if (nums[i] == x1) {
                count1++;
            }
            if (nums[i] == x2) {
                count2++;
            }
        }
        if (count1 > t / 3)
            ans.push_back(x1);
        if (count2 > t / 3&& x1!=x2)
            ans.push_back(x2);
        return ans;
    }
};