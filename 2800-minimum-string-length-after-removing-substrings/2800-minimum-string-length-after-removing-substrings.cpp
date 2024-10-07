class Solution {
public:
    int minLength(string s) {
        int length=s.length();
        stack<char>st;
        for(int i=0;i<length;i++){
            if(st.empty())st.push(s[i]);
            else if(st.top()=='C'&& s[i]=='D')st.pop();
            else if(st.top()=='A'&&s[i]=='B')st.pop();
            else st.push(s[i]);
        }
        return st.size();
    }
};