class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>ar1(26,0),ar2(26,0);
        int l1=s1.length();
        int l2=s2.length();
        int count=0;
        if(l1!=l2)return false;
        for(int i=0;i<l1;i++){
            ar1[s1[i]-'a']++;
            ar2[s2[i]-'a']++;
            if(s1[i]!=s2[i])count++;
        }
        if(count>2)return false;
        for(int i=0;i<26;i++){
            if(ar1[i]!=ar2[i])return false;
        }
        return true;
    }
};