class Solution {
public:
    bool canReach(string s, int minJ, int maxJ) {
        if (s.back() == '1') return false; // Can't reach the last index if it's '1'
        
        int n = s.size();
        queue<int> q;
        q.push(0); // Start BFS from the first index
        int farthest = 0; // Tracks the farthest index processed

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // Start checking from the max of (farthest + 1) to avoid revisiting indices
            for (int i = max(curr + minJ, farthest + 1); i <= min(curr + maxJ, n - 1); i++) {
                if (s[i] == '0') { // If the index is reachable
                    if (i == n - 1) return true; // Early termination if last index is reached
                    q.push(i);
                }
            }
            farthest = max(farthest, curr + maxJ); // Update the farthest index processed
        }

        return false; // If BFS completes and last index is not reached
    }
};
