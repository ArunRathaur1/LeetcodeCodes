class Solution {
public:
    int minimumLength(string s) {
       vector<int>ar(26,0);
       int l=s.length();
       for(int i=0;i<l;i++){
            ar[s[i]-'a']++;
       } 
       int count=0;
       for(int i=0;i<26;i++){
            if(ar[i]>0)
                count+=(ar[i]%2==0)?2:1;
       }
       return count;
    }
};