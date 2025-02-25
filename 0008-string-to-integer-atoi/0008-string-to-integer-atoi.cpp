class Solution {
public:
    int  myAtoi(string s) {
        int sign=0;
        long long number=0;
        int index=0;
        while(s[index]==' ')index++;
        if(s[index]=='-'){
            sign=1;
            index++;
        }
        else if(s[index]=='+'){
            index++;
        }
        int l=s.length();
        for(int i=index;i<l;i++){
            if(s[i]>='0'&& s[i]<='9'){
                number=number*10+1LL*(s[i]-'0');
            }
            else break; 
            if(number*-1<=(long long)INT_MIN&& sign==1)return INT_MIN;
            if(number>=(long long)INT_MAX&& sign==0)return INT_MAX;
            cout<<number<<endl;
        }
        if(sign==1){
            cout<<"h";
            return -1*number;
        }
        return number;
    }
};