class Solution {
public:
    bool compare_map(const unordered_map<char,int>&m1,const unordered_map<char,int>&m2){
       return m1==m2;
    }
    bool checkInclusion(string s1, string s2) {
        int right=s1.length();
        int end=s2.length();
        if(right>end)return false;
        unordered_map<char,int>m1,m2;
        for(auto c:s1)m1[c]++;
        for(int i=0;i<right;i++)m2[s2[i]]++;
        if(compare_map(m1,m2))return true;
        for(int i=right;i<end;i++){
            m2[s2[i]]++;
            m2[s2[i-right]]--;
            if(m2[s2[i-right]]==0)
                m2.erase(s2[i-right]);
            if(compare_map(m1,m2))return true;
        }
        return false;
    }
};