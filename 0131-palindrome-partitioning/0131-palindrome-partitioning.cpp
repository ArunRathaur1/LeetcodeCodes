class Solution {
public:
    void allparts(string s ,int index,vector<string>&ans,int n,vector<vector<string>>&ar,map<pair<int,int>,int>&dp){
        if(index>n)return;
        if(index==n){
            ar.push_back(ans);
        }
        for(int i=index;i<n;i++){
            if(dp.find({i+1,index+1})==dp.end()){
                int left=index;
                int right=i;
                int flag=0;
                while(left<right){
                if(s[left]==s[right]){
                    left++;
                    right--;
                }
                else{
                    flag=1;
                    break;
                    }
                }
                dp[{(i+1),(index+1)}]=flag==0?1:0;

            }
            if(dp[{(i+1),(index+1)}]==1){
                string tem=s.substr(index,i-index+1);
                ans.push_back(tem);
                allparts(s,i+1,ans,n,ar,dp);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ar;
        vector<string>ans;
        int l=s.length();
        map<pair<int,int>,int>dp;
        allparts(s,0,ans,l,ar,dp);
        return ar;
    }
};