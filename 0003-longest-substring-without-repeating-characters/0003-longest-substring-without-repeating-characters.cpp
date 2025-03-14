class Solution {
public:
    bool checkfreq(vector<int>ar){
        for(int i=0;i<128;i++){
            if(ar[i]>=2)return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        vector<int>freq(128,0);
       int l=s.length();
       int left=0;
       int ans=0;
       for(int i=0;i<l;i++){
            freq[s[i]]++;
            while(checkfreq(freq)){
                freq[s[left]]--;
                left++;
            }
            ans=max(ans,i-left+1);
       } 
       return ans;
    }
};