class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& st) {
        int x = st.size();
        int p = s.length();
        vector<int> tst(p + 1, 0);  // Adjust size to p+1 to avoid boundary issues

        // Process each shift query
        for (int i = 0; i < x; i++) {
            int start = st[i][0];
            int end = st[i][1];
            int direction = st[i][2];

            if (direction == 1) {  // Forward shift
                tst[start] += 1;
                if (end + 1 < p) tst[end + 1] -= 1;
            } else {  // Backward shift
                tst[start] -= 1;
                if (end + 1 < p) tst[end + 1] += 1;
            }
        }

        // Calculate the cumulative shifts
        int shift = 0;
        for (int i = 0; i < p; i++) {
            shift += tst[i];
            // Apply the shift to the character
            s[i] = ((s[i] - 'a' + shift) % 26 + 26) % 26 + 'a';
        }

        return s;
    }
};
