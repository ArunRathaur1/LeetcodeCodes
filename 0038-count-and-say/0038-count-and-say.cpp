class Solution {
public:
    string count(int n){
        if(n==1)return "1";
        string p=count(n-1);
        string ans="";
        int c=0;
        char ch=p[0];
        int l=p.length();
        for(int i=0;i<l;i++){
            if(ch==p[i]){
                c++;
            }
            else{
                ans.append(to_string(c)+ch);
                ch=p[i];
                c=1;
            }
        }
        ans.append(to_string(c)+ch);
        return ans;
    }
    string countAndSay(int n) {
        return count(n);
    }
};