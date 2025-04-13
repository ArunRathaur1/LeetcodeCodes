class Solution {
public:
    long long mod = 1e9 + 7;

    long long powercalculator(long long number, long long power) {
        if (power == 0) return 1;
        if (power == 1) return number % mod;

        long long half = powercalculator(number, power / 2) % mod;
        long long result = (half * half) % mod;

        if (power % 2 == 1) {
            result = (result * (number % mod)) % mod;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenPos = n / 2;  
        long long oddPos = (n + 1) / 2;

        long long result = (powercalculator(5, oddPos) * powercalculator(4, evenPos)) % mod;
        return result;
    }
};
