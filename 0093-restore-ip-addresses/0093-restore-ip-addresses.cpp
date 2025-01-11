class Solution {
public:
    void generate(string&s,vector<string>&ar,string ans,int index,int&n,int count){
        if(index>n)return ;
        if(index==n){
            ans.pop_back();
            cout<<ans<<endl;
            if(count==4)
                ar.push_back(ans);
            return;
        }
        if(s[index]=='0'){
            ans=ans+'0'+'.';
            generate(s,ar,ans,index+1,n,count+1);
        }
        else{
            if(index<n)
                generate(s,ar,ans+s[index]+'.',index+1,n,count+1);
            if(index+1<n)
                generate(s,ar,ans+s[index]+s[index+1]+".",index+2,n,count+1);
            if(index+2<n){
                int number=(s[index]-'0')*100+(s[index+1]-'0')*10+(s[index+2]-'0');
                if(number<=255){
                    generate(s,ar,ans+s[index]+s[index+1]+s[index+2]+'.',index+3,n,count+1);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ar;
        string ans="";
        int n=s.length();
        generate(s,ar,ans,0,n,0);
        return ar;
    }
};