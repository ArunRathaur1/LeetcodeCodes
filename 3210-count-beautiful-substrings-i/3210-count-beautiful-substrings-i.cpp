class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int count=0;
        int l=s.length();
        for(int i=0;i<l;i++){
            int v=0,c=0;
            for(int j=i;j<l;j++){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                v++;
                }
                else{
                    c++;
                }
                if(v==c&&(v*c)%k==0){
                    count++;
                }
            }
        }
        return count;
    }
};