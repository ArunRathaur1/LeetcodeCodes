class Solution {
public:
    bool checkfreq(vector<int>ar,int k){
        int mp=0;
        int count=0;
        for(int i=0;i<26;i++){
            if(ar[i]>mp)mp=ar[i];
            count=count+ar[i];
        }
        if(count-mp>k)return true;
        return false;
    }
    int characterReplacement(string s, int k) {
       int l=s.length();
       int left=0;
       int ans=0;
       vector<int>freq(26,0);
       for(int i=0;i<l;i++){
            freq[s[i]-'A']++;
            while(checkfreq(freq,k)){
                freq[s[left]-'A']--;
                left++;
            }
            ans=max(ans,i-left+1);
       } 
       return ans;
    }
};