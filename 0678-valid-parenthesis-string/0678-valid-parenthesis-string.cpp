class Solution {
public:
    bool checkValid(string& s,int index,int& n,int leftcount,vector<vector<int>>&dp){
        if(index==n){
           if(leftcount==0)return true;
           return false;
        }
        if(leftcount<0)return false;
        if(dp[index][leftcount]!=-1)return dp[index][leftcount];
        bool valid=false;

        if(s[index]==')')
        valid=valid||checkValid(s,index+1,n,leftcount-1,dp);
        else if(s[index]=='(')
        valid=valid|| checkValid(s,index+1,n,leftcount+1,dp);
        else{
            s[index]='A';
            valid=valid||checkValid(s,index+1,n,leftcount,dp);

            s[index]='(';
            valid=valid||checkValid(s,index+1,n,leftcount+1,dp);

            s[index]=')';
            valid=valid||checkValid(s,index+1,n,leftcount-1,dp);
            s[index]='*';
        }
        dp[index][leftcount]=valid;
        return valid;
    }
    bool checkValidString(string s) {
        int p=s.length();
        int leftcount=0;
        vector<vector<int>>dp(p+1,vector<int>(p+1,-1));
        return checkValid(s,0,p,leftcount,dp);
    }
};