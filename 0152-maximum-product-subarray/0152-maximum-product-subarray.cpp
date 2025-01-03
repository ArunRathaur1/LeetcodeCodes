class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0]; // Stores the overall maximum product
        int currentMax = nums[0]; // Tracks the current maximum product
        int currentMin = nums[0]; // Tracks the current minimum product
        
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                // Swap currentMax and currentMin when nums[i] is negative
                swap(currentMax, currentMin);
            }
            currentMax = max(nums[i], currentMax * nums[i]);
            currentMin = min(nums[i], currentMin * nums[i]);
            
            maxProduct = max(maxProduct, currentMax);
        }
        
        return maxProduct;
    }
};
