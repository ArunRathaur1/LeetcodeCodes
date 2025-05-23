class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        int l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};