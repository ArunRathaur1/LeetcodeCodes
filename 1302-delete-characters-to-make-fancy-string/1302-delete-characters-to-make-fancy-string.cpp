class Solution {
public:
    string makeFancyString(string &s) {
        int count=0;
        char curr=s[0];
        int length=s.length();
        string ans="";
        for(int i=0;i<length;i++){
            if(s[i]!=curr){
                count=1;
                ans.push_back(s[i]);
                curr=s[i];
            }
            else if(curr==s[i]&&count<2){
                ans.push_back(s[i]);
                count++;

            } 

        }
        return ans;
    }
};