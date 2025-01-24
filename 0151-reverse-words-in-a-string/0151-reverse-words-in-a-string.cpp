class Solution {
public:
    string reverseWords(string s) {
        string s1="";
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(s1.length()>0){
                    if(ans=="")
                        ans=s1;
                    else{
                        ans=s1+" "+ans;
                    }
                    s1="";
                }
            }
            else{
                s1+=s[i];
            }
        }
        if(s1.length()>0){
            if(ans=="")
                        ans=s1;
                    else{
                        ans=s1+" "+ans;
                    }
        }
        return ans;
    }
};