class Solution {
public:
    int maxUniqueSplit(string s) {
        set<string> st;
        return helper(s, st, 0);
    }
    
    int helper(string& s, set<string>& st, int index) {
        if (index == s.length()) return 0;
        
        int maxSplit = 0;
        for (int i = index; i < s.length(); i++) {
            string substring = s.substr(index, i - index + 1);
            if (st.find(substring) == st.end()) {  // Check if it's unique
                st.insert(substring);
                maxSplit = max(maxSplit, 1 + helper(s, st, i + 1));  // Recur for the remaining part
                st.erase(substring);  // Backtrack
            }
        }
        return maxSplit;
    }
};
