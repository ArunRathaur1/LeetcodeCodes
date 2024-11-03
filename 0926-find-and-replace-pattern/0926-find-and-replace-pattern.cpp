class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int size = words.size();
        
        for (int i = 0; i < size; i++) {
            string s1 = words[i];
            map<char, char> m1;
            map<char,char>m2;
            if (s1.length() != pattern.length()) continue;
            
            int flag = 0;
            for (int j = 0; j < s1.length(); j++) {
                if (m1.find(pattern[j]) == m1.end()&& m2.find(s1[j])==m2.end()) {
                    m1[pattern[j]] = s1[j];
                    m2[s1[j]]=pattern[j];
                } 
                else if (m1[pattern[j]] != s1[j]) {
                    flag = 1;
                    break;
                }
            }
            
            if (flag == 0) {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
};
