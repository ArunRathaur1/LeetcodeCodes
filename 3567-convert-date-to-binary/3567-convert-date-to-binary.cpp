class Solution {
public:
    string Binary(string data){
        int n=stoi(data);
        string b="";
        while(n!=0){
            int tem=n%2;
            if(tem==1)
                b+='1';
            else 
                b+='0';
            n=n/2;
        }
        reverse(b.begin(),b.end());
        return b;
    }
    string convertDateToBinary(string s) {
        int left=0;
        string ans="";
        int n=s.length();
        for(int i=0;i<=n;i++){
            if(s[i]=='-'||i==n){
                string q=s.substr(left,i-left+1);
                string out=Binary(q);
                if(i!=n)
                ans+=out+'-';
                else ans+=out;
                left=i+1;
            }
        }
        return ans;
    }
};