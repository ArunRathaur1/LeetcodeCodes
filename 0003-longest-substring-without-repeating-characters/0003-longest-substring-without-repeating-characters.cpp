class Solution {
public:
    bool checkfreq(map<char,int>ar){
        for(auto i:ar){
            if(i.second>=2)return true;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
       map<char,int>freq;
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