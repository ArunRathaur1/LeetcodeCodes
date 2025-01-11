class Solution {
public:
    bool answer(string& s1, string& s2,string& s3,int i1,int i2,int i3,int& n1,int& n2,int& n3,vector<vector<int>>&dp){
        if(i1==n1&& i2==n2&& i3==n3)return true;
        if(i1>n1||i2>n2||i3>n3)return false;
        if(dp[i1][i2]!=-1)return (dp[i1][i2]==1?true:false);
        bool result=false;
        if(s1[i1]==s3[i3]&& s2[i2]==s3[i3]){
            result= answer(s1,s2,s3,i1+1,i2,i3+1,n1,n2,n3,dp)||
                answer(s1,s2,s3,i1,i2+1,i3+1,n1,n2,n3,dp);
        }
        else if(s1[i1]==s3[i3]){
            result= answer(s1,s2,s3,i1+1,i2,i3+1,n1,n2,n3,dp);
        }
        else if(s2[i2]==s3[i3]){
            result= answer(s1,s2,s3,i1,i2+1,i3+1,n1,n2,n3,dp);
        }
        dp[i1][i2]=result==true?1:0;
        return result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length();
        int n2=s2.length();
        int n3=s3.length();
       vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return answer(s1,s2,s3,0,0,0,n1,n2,n3,dp);
    }
};