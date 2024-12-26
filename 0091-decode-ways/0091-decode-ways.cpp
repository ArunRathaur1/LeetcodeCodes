class Solution {
public:
    int totalways(int index,string s,int length,vector<int>&dp){
        if(index>length||s[index]=='0')return 0;
        if(index==length)return 1;
        if(dp[index]!=-1)return dp[index];
        int case1=totalways(index+1,s,length,dp);
        int case2=0;
        int number=(s[index]-'0')*10+(s[index+1]-'0');
        if(index+1<length&& number<=26){
            case2=totalways(index+2,s,length,dp);
        }
        dp[index]=case1+case2;
        return dp[index];
    }
    int numDecodings(string s) { 
        if(s[0]==0)return 0;
        int flag=1;
        int length=s.length();
        vector<int>dp(length,-1);
        for(int i=1;i<length;i++){
            if(s[i]=='0'&& s[i-1]>'2'){
                flag=-1;
                break;
            }
        }
        if(flag==1){
            return totalways(0,s,length,dp);
        }
        else{
            return 0;
        }
    }
};