class Solution {
public:
    bool checkValidString(string s) {
        int mi=0;
        int ma=0;
        int l=s.length();
        for(int i=0;i<l;i++){
            if(s[i]=='('){
                mi++;
                ma++;
            }
            else if(s[i]==')'){
                if(mi>0)mi--;
                if(ma>0)ma--;
                else return false;
            }
            else {
                if(mi>0)mi--;
                ma++;
            }
        }
        if(mi==0)return true;
        return false;
    }
};