class Solution {
public:
    string removeOuterParentheses(string s) {
        int l = s.length();
        stack<char> st;
        string ans = "";
        int mark = 0;
        for (int i = 0; i < l; i++) {
            if(s[i]=='('){
                if(mark>=1){
                    ans+="(";
                }
                mark++;
            }
            else if(s[i]==')')
            {
                mark--;
                if(mark>0)
                    ans+=")";
            }  
        }
        return ans;
    }
};