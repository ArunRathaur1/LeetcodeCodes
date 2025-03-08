class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        int L = n + m - 1;
        vector<char> res(L, 'a'); // Default fill with 'a'
        vector<char> forced(L, 0); // Store forced characters, 0 means not forced
        
        // Step 1: Process 'T' conditions
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    int p = i + j;
                    if (forced[p] != 0 && forced[p] != str2[j]) {
                        return ""; // Conflict
                    }
                    forced[p] = str2[j];
                }
            }
        }
        
        // Step 2: Precompute F intervals
        struct Interval {
            int start, end, candidate, last_free;
            bool satisfied;
        };
        
        vector<Interval> F_intervals;
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool satisfied = false;
                int candidate = -1, last_free = -1;
                for (int x = i; x < i + m; x++) {
                    if (forced[x] != 0) {
                        if (forced[x] != str2[x - i]) {
                            satisfied = true;
                        }
                    } else {
                        last_free = max(last_free, x);
                        if (str2[x - i] != 'a' && (candidate == -1 || x < candidate)) {
                            candidate = x;
                        }
                    }
                }
                if (!satisfied && last_free == -1) {
                    return ""; // Impossible case
                }
                F_intervals.push_back({i, i + m - 1, candidate, last_free, satisfied});
            }
        }
        
        // Step 3: Greedy scan over positions
        vector<Interval*> active;
        int interval_index = 0;
        
        for (int p = 0; p < L; p++) {
            // Add new intervals
            while (interval_index < F_intervals.size() && F_intervals[interval_index].start == p) {
                active.push_back(&F_intervals[interval_index]);
                interval_index++;
            }
            
            // Remove expired intervals
            active.erase(remove_if(active.begin(), active.end(), 
                                   [p](Interval* iv) { return p > iv->end; }), active.end());
            
            // Decide letter at position p
            if (forced[p] != 0) {
                res[p] = forced[p];
            } else {
                bool force_dev = false;
                for (auto iv : active) {
                    if (!iv->satisfied && iv->candidate == -1 && p == iv->last_free) {
                        force_dev = true;
                        break;
                    }
                }
                res[p] = force_dev ? 'b' : 'a';
            }
            
            // Update active intervals
            for (auto iv : active) {
                if (!iv->satisfied && p >= iv->start && p <= iv->end) {
                    if (res[p] != str2[p - iv->start]) {
                        iv->satisfied = true;
                    }
                }
            }
            
            // Check for unsatisfied intervals
            for (auto iv : active) {
                if (p == iv->end && !iv->satisfied) {
                    return "";
                }
            }
        }
        
        return string(res.begin(), res.end());
    }
};
