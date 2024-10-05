class Solution {
public:
    // bool compare_map(const unordered_map<char,int>&m1,const unordered_map<char,int>&m2){
    //    return m1==m2;
    // }
    bool checkInclusion(string s1, string s2) {
        int right=s1.length();
        int end=s2.length();
        if(right>end)return false;
        // unordered_map<char,int>m1,m2;
        vector<int>m1(26,0),m2(26,0);
        for(auto c:s1)m1[c-'a']++;
        for(int i=0;i<right;i++)m2[s2[i]-'a']++;
        if(m1==m2)return true;
        for(int i=right;i<end;i++){
            m2[s2[i]-'a']++;
           
            if(m2[s2[i-right]-'a']!=0)
                 m2[s2[i-right]-'a']--;
            if(m1==m2)return true;
        }
        return false;
    }
};