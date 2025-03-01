class Solution {
public:
    bool check(string s ,int index, string word){
        int p=0;
        int x=s.length();
        while(index<x&&s[index]==word[p]){
            p++;
            index++;
        }
        if(p==word.length())return true;
        return false;
    }
    bool possible(string s,int n,int length,vector<string>&wordDict,int index,vector<int>&dp){
        if(index==n){
            return true;
        }
        if(dp[index]!=-1)return dp[index];
        for(int i=0;i<length;i++){
            if(check(s,index,wordDict[i])){
                bool canbreak=possible(s,n,length,wordDict,index+wordDict[i].length(),dp);
                if(canbreak){
                    dp[index]=1;
                    return true;
                }
            }
        }
        dp[index]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        int length=wordDict.size();
        int index=0;
        vector<int>dp(n+1,-1);
        return possible(s,n,length,wordDict,index,dp);
    }
};