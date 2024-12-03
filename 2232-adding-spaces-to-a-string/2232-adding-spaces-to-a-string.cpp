#include <sstream>

class Solution {
public:
    string addSpaces(string s, vector<int>& ar) {
        stringstream out;
        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            if (index < ar.size() && ar[index] == i) {
                out << " ";
                index++;
            }
            out << s[i];
        }
        return out.str();
    }
};
