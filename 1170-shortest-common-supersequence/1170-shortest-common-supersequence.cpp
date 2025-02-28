class Solution {
public:
    string longest(string str1,string str2){
        int l1=str1.length();
        int l2=str2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i=1;i<l1+1;i++){
            for(int j=1;j<l2+1;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string longest="";
        int d=l1;
        int r=l2;
        while(d>0&& r>0){
            if(str1[d-1]==str2[r-1]){
                longest+=str1[d-1];
                d=d-1;
                r=r-1;
            }
            else if(dp[d][r-1]>=dp[d-1][r]){
                longest+=str2[r-1];
                r=r-1;
            }
            else{
                longest+=str1[d-1];
                d=d-1;
            }
        }
        while(d>0){
            longest+=str1[d-1];
            d--;
        }
        while(r>0){
            longest+=str2[r-1];
            r--;
        }
        reverse(longest.begin(),longest.end());
        return longest;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string p=longest(str1,str2);
        return p;
    }
};