class Solution {
public:
    int maxsplits(string s,int l,int start,set<string>&seen){
        if(start==s.size()){
            return 0;
        }
        int m=0;
        for(int i=start;i<l;i++){
            string p=s.substr(start,i-start+1);
            if(seen.find(p)==seen.end()){
                seen.insert(p);
                m=max(m,1+maxsplits(s,l,i+1,seen));
                seen.erase(p);
            }
            
        }
        return m;
    }
    int maxUniqueSplit(string s) {
        set<string>s1;
        return maxsplits(s,s.length(),0,s1);
    }
};