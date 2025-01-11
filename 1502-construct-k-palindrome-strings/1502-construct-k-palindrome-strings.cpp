class Solution {
public:
    bool canConstruct(string s, int k) {
        vector<int>ar(26,0);
        int n=s.length();
        if(k>n)return false;
        for(int i=0;i<n;i++){
            ar[s[i]-'a']++;
        }
        int minpalindrome=0;
        for(auto ch:ar){
            if(ch%2!=0){
                minpalindrome++;
            }
        }
        if(k<minpalindrome)return false;
        return true;
    }
};