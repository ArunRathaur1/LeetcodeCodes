class Solution {
public:
    int minimumLength(string s) {
        int length = s.length();
        int ans = length;
        
        for (int i = 0; i < length; i++) {
            if (s[i] == 'A') continue;
            
            int n1 = -1;
            for (int j = i-1; j>=0; j--) {
                if (s[i] == s[j]) {
                    n1 = j;
                    break;
                }
            }
            if (n1 == -1) continue;
            
            int n2 = -1;
            for (int j = i + 1; j < length; j++) {
                if (s[i] == s[j]) {
                    n2 = j;
                    break;
                }
            }
            if (n2 == -1) continue;
            
            if (n1 != -1 && n2 != -1) {
                ans -= 2;
                s[n1] = 'A';
                s[n2] = 'A';
            }
        }
        
        return ans;
    }
};
