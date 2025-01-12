class Solution {
public:
    bool canform(string s,vector<string>&wordDict,int index,int n,int l,vector<int>&dp){
        if(index==n)return true;
        if(index>n)return false;
        if(dp[index]!=-1)return dp[index];
        bool output=false;
        for(int i=0;i<l;i++){
            int length=wordDict[i].length();
            if(length<=n-index&& s.substr(index,length)==wordDict[i]){
                 dp[index]=canform(s,wordDict,index+length,n,l,dp);
                 if(dp[index]==true){
                    return true;
                 }
            }
        }
        return dp[index]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int l=wordDict.size();
        int n=s.length();
        vector<int>dp(s.length(),-1);
        return canform(s,wordDict,0,n,l,dp);
    }
};