class Solution {
public:
    string reverseWords(string s) {
        string s1="";
        int n=s.length();
        string ans="";
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(s1.length()>0){
                    reverse(s1.begin(),s1.end());
                    ans=ans+s1+" ";
                    s1="";
                }
            }
            else{
                s1+=s[i];
            }
        }
        if(s1.length()>0){
            reverse(s1.begin(),s1.end());
            ans=ans+s1+" ";
        }
        return ans.substr(0,ans.length()-1);
    }
};