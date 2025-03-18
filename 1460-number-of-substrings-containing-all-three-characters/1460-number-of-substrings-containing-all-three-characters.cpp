class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>m;
        int l=s.length();
        int ans=0;
        int left=0;
        for(int i=0;i<l;i++){
            m[s[i]]++;
            while(m.size()==3){
                ans=ans+(l-i);
                m[s[left]]--;
                if(m[s[left]]==0)m.erase(s[left]);
                left++;
            }
        }
        return ans;
    }
};