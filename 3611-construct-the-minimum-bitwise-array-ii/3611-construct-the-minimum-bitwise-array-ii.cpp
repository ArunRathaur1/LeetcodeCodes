class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& input) {
        vector<int> output;

        for (int i = 0; i < input.size(); i++) {
            int number = input[i];
            vector<int> binaryDigits;
            while (number > 0) {
                int remainder = number % 2;
                number = number / 2;
                binaryDigits.push_back(remainder);
            }

            reverse(binaryDigits.begin(), binaryDigits.end());

            if (binaryDigits[binaryDigits.size() - 1] == 0) {
                output.push_back(-1);
            } else {
                int minValue = INT_MAX;

                for (int j = binaryDigits.size() - 1; j >= 0; j--) {
                    bool originalBit = binaryDigits[j];
                    binaryDigits[j] = 0;
                    int currentValue = 0;
                    for (int k = binaryDigits.size() - 1; k >= 0; k--) {
                        currentValue += binaryDigits[k] * pow(2, binaryDigits.size() - k - 1);
                    }

                    if ((currentValue | (currentValue + 1)) == input[i]) {
                        minValue = min(minValue, currentValue);
                    }
                    if (originalBit == 1) {
                        binaryDigits[j] = 1;
                    }
                }

                if (minValue == INT_MAX) {
                    output.push_back(-1);
                } else {
                    output.push_back(minValue);
                }
                cout << minValue << " ";
            }
        }

        return output;
    }
};
