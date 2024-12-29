class Solution {
public:
    int value=1e9+7;
    int totalways(string& target,int index,int& length,int target_index,int& target_length,vector<unordered_map<char,int>>&freq,vector<vector<int>>&dp){
        if(target_length==target_index)return 1;
        if(length-index<target_length-target_index)return 0;
        if(dp[index][target_index]!=-1)return dp[index][target_index];
        int total=0;
            if(freq[index].count(target[target_index])){
                long long tem=(1LL*totalways(target,index+1,length,target_index+1,target_length,freq,dp)*freq[index][target[target_index]])%value;
                total=(total+tem)%value;
            }
            int tem2=totalways(target,index+1,length,target_index,target_length,freq,dp)%value;
            total=(total+tem2)%value;
            dp[index][target_index]=total;
        return total;
    }
    int numWays(vector<string>& words, string target) {
        int l=words.size();
        int word_length=words[0].length();
        vector<unordered_map<char,int>>m(word_length);
        for(int i=0;i<word_length;i++){
            for(int j=0;j<l;j++){
                m[i][words[j][i]]++;
            }
        }
        vector<vector<int>>dp(word_length,vector<int>(target.length(),-1));
        int target_length=target.length();
        return totalways(target,0,word_length,0,target_length,m,dp);
    }
};