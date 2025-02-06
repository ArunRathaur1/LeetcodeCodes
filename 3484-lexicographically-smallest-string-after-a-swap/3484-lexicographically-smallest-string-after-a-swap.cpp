class Solution {
public:
    string getSmallestString(string s) {
        int l=s.length();
        for(int i=0;i<l;i++){
            if(i+1>=l)break;
            int p1=s[i]-'0';
            int p2=s[i+1]-'0';
            if(((p1%2==0&& p2%2==0)||(p1%2==1&& p2%2==1))&&(p1>p2)){
                swap(s[i],s[i+1]);
                return s;
            }
        }
        return s;
    }
};