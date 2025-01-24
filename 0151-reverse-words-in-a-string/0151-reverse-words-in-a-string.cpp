class Solution {
public:
    string reverseWords(string s) {
        s+=' ';
        int left=0;
        int right=0;
        int l=s.length();
        string ans="";
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
                    ans=s.substr(left,right-left);
                }
                else{
                    ans=s.substr(left,right-left)+" "+ans;
                }
            }
        }
        return ans;
    }
};