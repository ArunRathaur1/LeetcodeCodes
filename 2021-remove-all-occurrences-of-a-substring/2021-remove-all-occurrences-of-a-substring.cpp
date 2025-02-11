class Solution {
public:
    string removeOccurrences(string s, string part) {
        int l=part.length();
        while(s.find(part)!=string::npos){
            int p=s.find(part);
            s=s.substr(0,p)+s.substr(p+l);
        }
        return s;
    }
};