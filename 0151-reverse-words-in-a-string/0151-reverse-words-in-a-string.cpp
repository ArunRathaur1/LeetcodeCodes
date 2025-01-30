class Solution {
public:
    string reverseWords(string s) {
        s+=' ';
        int left=0;
        int right=0;
        int l=s.length();
        string ans="";
        stack<string>st;
        while(right<l){
            if(s[right]==' '){
                right++;
            }
            else{
                left=right;
                while(s[right]!=' '){
                    right++;
                }
                if(ans==""){
                    st.push(s.substr(left,right-left));
                }
                else{
                    st.push(s.substr(left,right-left));
                }
            }
        }
        while(st.size()>1){
            ans+=(st.top()+" ");
            st.pop();
        }
        ans+=st.top();
        return ans;
    }
};