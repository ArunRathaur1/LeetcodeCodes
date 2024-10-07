class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int totalSum = 0;
        
        // Compute total sum of the array
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        
        // If the total sum is already divisible by p, no subarray needs to be removed
        if (totalSum == 0) {
            return 0;
        }
        
        // We need to find a subarray with sum % p = totalSum % p
        int target = totalSum;
        int currSum = 0;
        unordered_map<int, int> prefixMod;
        prefixMod[0] = -1;  // to handle the case where the subarray starts from the beginning
        
        int minLength = n;
        for (int i = 0; i < n; ++i) {
            currSum = (currSum + nums[i]) % p;
            int need = (currSum - target + p) % p;  // find the remainder that would balance out to the target
            
            // If we find the needed remainder in the prefix map, calculate the subarray length
            if (prefixMod.find(need) != prefixMod.end()) {
                minLength = min(minLength, i - prefixMod[need]);
            }
            
            // Store the current prefix sum remainder with its index
            prefixMod[currSum] = i;
        }
        
        // If no valid subarray found, return -1, else return minLength
        return minLength == n ? -1 : minLength;
    }
};
