class Solution {
public:
    void generate(int open,int close,vector<string>&ans,string s){
        if(open==0&& close==0){
            ans.push_back(s);
            return;
        }
        if(open>0)
        generate(open-1,close,ans,s+'(');
        if(close>open)
        generate(open,close-1,ans,s+')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        generate(n,n,ans,s);
        return ans;
    }
};