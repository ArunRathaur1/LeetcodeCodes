class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int l1=text1.length();
        int l2=text2.length();
        vector<vector<int>>dp(l1+1,vector<int>(l2+1,0));
        for(int i=l1-1;i>=0;i--){
            for(int j=l2-1;j>=0;j--){
                int matched=0,c2=0,c3=0;
            if(text1[i]==text2[j]){
            matched=1+dp[i+1][j+1];
            }
            else{ 
                    c2=dp[i+1][j];
                    c3=dp[i][j+1];
            }
            dp[i][j]=max({matched,c2,c3});
        }
    }
    return dp[0][0];
    }
};

