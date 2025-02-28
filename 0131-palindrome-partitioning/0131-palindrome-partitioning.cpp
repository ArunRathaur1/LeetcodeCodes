class Solution {
public:
    bool check(string s){
        int left=0;
        int right=s.length()-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else return false;
        }
        return true;
    }
    void generate(string s,vector<string>&tem,vector<vector<string>>&ans,int index,int n){
        if(index>=n){
            ans.push_back(tem);
            return;
        }
        for(int i=index+1;i<=n;i++){
            string p=s.substr(index,i-index);
            if(check(p)==true){
                tem.push_back(p);
                generate(s,tem,ans,i,n);
                tem.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>tem;
        vector<vector<string>>ans;
        int n=s.length();
        generate(s,tem,ans,0,n);
        return ans;
    }
};