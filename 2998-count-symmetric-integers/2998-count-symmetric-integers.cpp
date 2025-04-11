class Solution {
public:
    bool symmetric(const string& p){
        int n = p.length() / 2;
        int left_sum = 0, right_sum = 0;
        for (int i = 0; i < n; ++i) {
            left_sum += p[i] - '0';
            right_sum += p[i + n] - '0';
        }
        return left_sum == right_sum;
    }

    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; ++i) {
            string p = to_string(i);
            if (p.length() % 2 == 0 && symmetric(p))
                count++;
        }
        return count;
    }
};
