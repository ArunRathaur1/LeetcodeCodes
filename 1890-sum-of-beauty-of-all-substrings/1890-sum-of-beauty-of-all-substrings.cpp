class Solution {
public:
    int beautySum(string s) {
       int l=s.length();
       int ans=0;
       for(int i=0;i<l;i++){
        vector<int>ar(26,0);
        for(int j=i;j<l;j++){
            ar[s[j]-'a']++;
            int max=*max_element(ar.begin(),ar.end());
            int minelement=INT_MAX;
            for(int k=0;k<26;k++){
                if(ar[k]!=0&& minelement>ar[k]){
                    minelement=ar[k];
                }
            }
            ans=ans+(max-minelement);
        }
       } 
       return ans;
    }
};