class Solution {
public:
    bool isCircularSentence(string s) {
        if(s[0]!=s[s.length()-1])return false;
        for(int i=0;i<s.length();i++){
            if(i-1>=0&& i+1<s.length()&& s[i]==' '&& s[i-1]!=s[i+1]){
                return false;
            }
        }
        return true;
    }
};