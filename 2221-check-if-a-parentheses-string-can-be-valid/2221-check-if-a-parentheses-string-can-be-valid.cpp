class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if (n % 2 != 0) return false; // Odd length cannot be valid
        
        int open = 0, balance = 0;

        // Forward pass: Ensure there are enough `(` to balance `)`
        for (int i = 0; i < n; i++) {
            if (locked[i] == '1') {
                open += (s[i] == '(' ? 1 : -1);
            } else {
                open++; // Unlocked can act as `(`
            }
            balance++;
            if (open < 0) return false; // Too many `)` locked
        }

        open = 0;
        balance = 0;

        // Backward pass: Ensure there are enough `)` to balance `(`
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '1') {
                open += (s[i] == ')' ? 1 : -1);
            } else {
                open++; // Unlocked can act as `)`
            }
            balance++;
            if (open < 0) return false; // Too many `(` locked
        }

        return true;
    }
};
