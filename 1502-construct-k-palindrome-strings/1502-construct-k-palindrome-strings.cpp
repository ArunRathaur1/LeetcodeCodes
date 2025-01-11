class Solution {
public:
    bool canConstruct(string s, int k) {
        map<char,int>freq;
        int n=s.length();
        if(k>n)return false;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        int minpalindrome=0;
        for(auto ch:freq){
            if(ch.second%2!=0){
                minpalindrome++;
            }
        }
        if(k<minpalindrome)return false;
        return true;
    }
};