class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=s.length();
        int ans=0;
        int most=0;
        int left=0;
        vector<int>freq(26,0);
        for(int i=0;i<l;i++){
            freq[s[i]-'A']++;
            most=max(most,freq[s[i]-'A']);
            int length=i-left+1;
            while(length-most>k){
                length--;
                freq[s[left]-'A']--;
                left++;
            }
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};