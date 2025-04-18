class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        string p=countAndSay(n-1);
        int m=p.length();
        string ans="";
        char current=p[0];
        int count=0;
        for(int i=0;i<=m;i++){
            if(i<m&&p[i]==current){
                count++;
            }
            else{
                ans+=to_string(count)+current;
                current=p[i];
                count=1;
            }
        } 
        return ans;
    }
};