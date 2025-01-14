class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int maxNumber = *max_element(nums.begin(), nums.end());
        int minNumber = *min_element(nums.begin(), nums.end());
        int size = nums.size();

        // Calculate bucket size and count
        int bucketSize = max(1, (maxNumber - minNumber) / (size - 1));
        int bucketCount = (maxNumber - minNumber) / bucketSize + 1;

        vector<vector<int>> buckets(bucketCount, vector<int>(2, -1)); // Stores [min, max]

        // Place numbers into buckets
        for (int num : nums) {
            if (num == minNumber || num == maxNumber) continue;

            int index = (num - minNumber) / bucketSize;
            if (buckets[index][0] == -1) { // Empty bucket
                buckets[index][0] = num;
                buckets[index][1] = num;
            } else {
                buckets[index][0] = min(buckets[index][0], num);
                buckets[index][1] = max(buckets[index][1], num);
            }
        }

        // Calculate the maximum gap
        int maxGap = 0;
        int previousMax = minNumber;

        for (const auto& bucket : buckets) {
            if (bucket[0] == -1) continue; // Skip empty buckets
            maxGap = max(maxGap, bucket[0] - previousMax);
            previousMax = bucket[1];
        }

        // Final gap between the last bucket and the maximum number
        maxGap = max(maxGap, maxNumber - previousMax);

        return maxGap;
    }
};
