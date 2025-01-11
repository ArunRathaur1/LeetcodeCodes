class Solution {
public:
    void allparts(string s ,int index,vector<string>&ans,int n,vector<vector<string>>&ar){
        if(index>n)return;
        if(index==n){
            ar.push_back(ans);
        }
        for(int i=index;i<n;i++){
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
            if(flag==0){
                string tem=s.substr(index,i-index+1);
                ans.push_back(tem);
                allparts(s,i+1,ans,n,ar);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ar;
        vector<string>ans;
        int l=s.length();
        allparts(s,0,ans,l,ar);
        return ar;
    }
};