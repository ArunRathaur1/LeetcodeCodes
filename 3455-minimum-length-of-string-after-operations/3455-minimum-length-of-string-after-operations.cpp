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
            if(ar[i]<=2)count=count+ar[i];
            else{
                if(ar[i]%2==0){
                    count=count+2;
                }
                else{
                    count++;
                }
            }
       }
       return count;
    }
};