class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        int length=s.length();
        unordered_map<string,int>ar;
        for(int i=0;i<length;i++){
            string s1=s.substr(i,10);
            if(ar.find(s1)!=ar.end()){
                if(ar[s1]==1)
                    ans.push_back(s1);
                ar[s1]++;
            }
            else{
                ar[s1]=1;
            }
        }
        return ans;
    }
};