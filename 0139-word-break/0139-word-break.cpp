class Solution {
public:
    bool canform(string s,vector<string>&wordDict,int index,int n,int l,vector<int>&dp){
        if(index==n)return true;
        if(index>n)return false;
        if(dp[index]!=-1)return dp[index]==1?true:false;
        bool output=false;
        for(int i=0;i<l;i++){
            string tem=wordDict[i];
            if(tem.length()>n-index){
                continue;
            }
            int p=index;
            int flag=0;
            for(int j=0;j<tem.length();j++){
                if(s[p]==tem[j]){
                    p++;
                }
                else{
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                dp[index]=canform(s,wordDict,p,n,l,dp)==true?1:0;
              if(dp[index]==1){
                return true;
              } 
            }
        }
        dp[index]=0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int l=wordDict.size();
        int n=s.length();
        vector<int>dp(s.length(),-1);
        return canform(s,wordDict,0,n,l,dp);
    }
};