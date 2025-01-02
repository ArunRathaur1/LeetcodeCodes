class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] == '1') return false; // Last index is unreachable

        queue<int> q;
        q.push(0); // Start BFS from the first index
        int farthest = 0; // Tracks the farthest processed index

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // Start checking from the max of (current + minJump, farthest)
            int start = max(current + minJump, farthest + 1);
            int end = min(current + maxJump, n - 1);

            for (int i = start; i <= end; ++i) {
                if (s[i] == '0') { // If reachable
                    if (i == n - 1) return true; // Early exit if last index is reached
                    q.push(i);
                }
            }

            farthest = max(farthest, current + maxJump); // Update farthest after processing
        }

        return false; // If BFS completes and last index is not reached
    }
};
