class Solution {
    private:
    // Helper function to split a string into words
    vector<string> splitWords(const string &s) {
        vector<string> result;
        stringstream ss(s);
        string word;
        
        while (ss >> word) {
            result.push_back(word);
        }
        
        return result;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
         string k1=s1.length()>s2.length()?s1:s2;
         string k2=s1==k1?s2:s1;
         vector<string> ch1=splitWords(k1);
         vector<string> ch2=splitWords(k2);
         int l1=ch1.size();
         int l2=ch2.size();
         int k=0;
         int l=0;
         while(l2>k&& ch1[k]==ch2[k]){
            k++;
         }
         while(l<l2&& ch1[l1-l-1]==ch2[l2-l-1]){
            l++;
         }
         if(l+k>=l2)return true;
         return false;
    }
};
