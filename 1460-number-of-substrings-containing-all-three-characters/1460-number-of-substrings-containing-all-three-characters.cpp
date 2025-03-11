class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char, int> m;
        int l = s.length();
        int ans = 0;
        int left = 0, right = 0;

        while (right < l) {
            m[s[right]]++;
            
            while (m.size() == 3) {
                ans += (l - right);  
                m[s[left]]--;
                if (m[s[left]] == 0) m.erase(s[left]);
                left++;
            }

            right++;
        }

        return ans;
    }
};
