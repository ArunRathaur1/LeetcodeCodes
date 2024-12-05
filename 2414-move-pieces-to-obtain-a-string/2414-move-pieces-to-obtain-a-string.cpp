class Solution {
public:
    bool canChange(string start, string target) {
        int i1 = 0, i2 = 0;
        int n = start.length();

        while (i1 < n || i2 < n) {
            while (i1 < n && start[i1] == '_') i1++;
            while (i2 < n && target[i2] == '_') i2++;

            if (i1 == n && i2 == n) return true;


            if (i1 == n || i2 == n) return false;
            if (start[i1] != target[i2]) return false;

            if ((start[i1] == 'L' && i1 < i2) || (start[i1] == 'R' && i1 > i2)) return false;

            i1++;
            i2++;
        }
        return true;
    }
};
