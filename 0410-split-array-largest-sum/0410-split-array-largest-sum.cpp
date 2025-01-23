class Solution {
public:
    bool possible(int mid, vector<int> ar, int painters, int size) {
        int required = 1;
        int cursum = 0;
        for (int i = 0; i < size; i++) {
            if (ar[i] > mid)
                return false;

            cursum = cursum + ar[i];
            if (cursum > mid) {
                required++;
                cursum = ar[i];
            }
            if (required > painters)
                return false;
        }
        return true;
    }
    int splitArray(vector<int>& ar, int painters) {
        int size = ar.size();
        int left = *max_element(ar.begin(), ar.end());
        int right = accumulate(ar.begin(), ar.end(), 0);
        int ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (possible(mid, ar, painters, size)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};