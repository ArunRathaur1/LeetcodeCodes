class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<string>st;
        int n=s.length();
        for(int i=0;i<26;i++){
            char ch=i+'a';
            int start=0;
            while(start<n&&s[start]!=ch)start++;
            int end=n-1;
            while(end>=0&&s[end]!=ch)end--;
            for(int j=start+1;j<end;j++){
                string sub="";
                sub=sub+ch+s[j]+ch;
                st.insert(sub);
            }
        }
        return st.size();
    }
};