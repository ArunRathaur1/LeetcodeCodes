class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.length()%2!=0)return false;
        int opening=0;
        int closing=0;
        int wildcard=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(locked[i]=='0')wildcard++;
            else if(s[i]=='(')opening++;
            else if(s[i]==')')closing++;
            if(wildcard+opening<closing)return false;
        }
        opening=0;
        closing=0;
        wildcard=0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0')wildcard++;
            else if(s[i]=='(')opening++;
            else if(s[i]==')')closing++;
            if(wildcard+closing<opening)return false;
        }
        return true;
    }
};