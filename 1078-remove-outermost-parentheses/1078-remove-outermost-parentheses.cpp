class Solution {
public:
    string removeOuterParentheses(string s) {
        int l = s.length();
        stack<char> st;
        string ans = "";
        string tem = "";
        int left = 0;
        for (int i = 0; i < l; i++) {
            if (st.empty()) {
                if (tem.length() >=2) {
                    ans = ans + tem.substr(1, tem.length() - 2);
                    tem = "";
                }
                st.push(s[i]);
            } else {
                if (!st.empty() && st.top() == '(' && s[i] == ')') {
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            tem.push_back(s[i]);
        }
        if(tem.length()>=2){
            ans = ans + tem.substr(1, tem.length() - 2);
            tem = "";
        }
        return ans;
    }
};