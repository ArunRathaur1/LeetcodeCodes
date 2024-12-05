class Solution {
public:
    bool canChange(string start, string target) {
       int i1=0 ,i2=0;
       int n1=start.length(),n2=target.length();
       while(i1<n1|| i2<n2){
        while(i1<n1&&start[i1]=='_')i1++;
        while(i2<n2&&target[i2]=='_')i2++;
        if(i1==n1&& i2==n2)return true;
        if(i1==n1||i2==n2)return false;
        if(start[i1]!=target[i2])return false;
        if((start[i1]=='R'&&i1>i2)||(start[i1]=='L'&& i1<i2))return false;
        i1++;
        i2++;
       } 
       return true;
    }
};