class Solution {
public:
    int compress(vector<char>& chars) {
        int count=0;
        char curr=chars[0];
        int size=chars.size();
        string ans="";
        for(int i=0;i<size;i++){
            if(chars[i]!=curr&&count==1){
                ans=ans+curr;
                count=1;
                curr=chars[i];
            }
            else if(chars[i]!=curr&& count>1){
                ans=ans+curr+to_string(count);
                count=1;
                curr=chars[i];
            }
            else if(chars[i]==curr){
                count++;
            }
        }
        if(count>1){
             ans=ans+curr+to_string(count);
        }
        else if(count==1){
            ans=ans+curr;
        }
        for(int i=0;i<ans.length();i++){
            chars[i]=ans[i];
        }
        return ans.length();
    }
};