class Solution {
public:
    map<char,int> count(string & t){
        map<char,int>m;
        for(auto i: t)m[i]++;
        return m;
    }
    bool check(map<char,int>&m){
        for(auto i: m){
            if(i.second>0)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int l=s.length();
        map<char,int>target=count(t);
        string ans="";
        int left=0;
        int index=0;
        int minlen=INT_MAX;
        for(int i=0;i<l;i++){
            target[s[i]]--;
            while(check(target)){
                if(minlen>(i-left+1)){
                    minlen=i-left+1;
                    index=left;
                }
                if(target.find(s[left])!=target.end()){
                    target[s[left]]++;
                }
                left++;
            }
        }
        return (minlen==INT_MAX)?"":s.substr(index,minlen);
    }
};