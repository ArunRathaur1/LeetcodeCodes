class Solution {
public:
    int  myAtoi(string s) {
        long long flag=0;
        long long number=0;
        long long n=s.length();
        char ch='+';
        for(long long i=0;i<n;i++){
            if(s[i]==' '&& flag==0)continue;
            else if((s[i]=='-'||s[i]=='+')&& flag==0){
                ch=s[i];
                flag=1;
            }
            else if(s[i]>='0'&& s[i]<='9'){
                flag=1;
                number=number*10+(s[i]-'0');
                if(number>INT_MAX&& ch=='+')return INT_MAX;
                else if(number>INT_MAX&& ch=='-')return INT_MIN;
            }
            else{
                break;
            }
        }
        if(ch=='-'){
            return -1*number;
        }
        return number;
        
    }
};