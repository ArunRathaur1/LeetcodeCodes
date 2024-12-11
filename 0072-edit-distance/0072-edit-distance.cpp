class Solution {
public:
    int operation(string& word1,string& word2,int i,int j,int l1,int l2,vector<vector<int>>&dp){
        if(i==l1)return l2-j;
        if(j==l2)return l1-i;
        if(dp[i][j]!=-1)return dp[i][j];

        if(word1[i]==word2[j])
           return operation(word1,word2,i+1,j+1,l1,l2,dp);


        int choice1=1+operation(word1,word2,i,j+1,l1,l2,dp);
        int choice2=1+operation(word1,word2,i+1,j,l1,l2,dp);
        int choice3=1+operation(word1,word2,i+1,j+1,l1,l2,dp);
        int op=min({choice1,choice2,choice3});
        dp[i][j]=op;
        return op;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length(),vector<int>(word2.length(),-1));
        return operation(word1,word2,0,0,word1.length(),word2.length(),dp);
    }
};