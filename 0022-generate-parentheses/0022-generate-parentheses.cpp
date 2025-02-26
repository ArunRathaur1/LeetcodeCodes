class Solution {
public:
    vector<string> generate(int open,int close){
        if(open==0&& close==0)return {""};
        vector<string>ans;
        if(open==close){
            vector<string>q=generate(open-1,close);
            for(int i=0;i<q.size();i++){
                ans.push_back(q[i]+")");
            }
        }
        else{
            if(open>0){
                vector<string>q=generate(open-1,close);
                for(int i=0;i<q.size();i++){
                    ans.push_back(q[i]+")");
                }
            }
            if(close>0){
                vector<string>q=generate(open,close-1);
                for(int i=0;i<q.size();i++){
                    ans.push_back(q[i]+"(");
                }
            }
        }
        return ans;
    }
    vector<string> generateParenthesis(int n) {
        return generate(n,n);
    }
};