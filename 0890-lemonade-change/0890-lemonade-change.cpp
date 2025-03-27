class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] == 10) {
                if ( five == 0) {
                    return false;
                } else {
                    five--;
                    ten++;
                }
            }
            if (bills[i] == 20) {
                if (five>=1&& ten>=1) {
                    five--;
                    ten--;
                } 
                else if(five>=3){
                    five=five-3;
                }
                else {
                    return false;
                }
            }

            if (bills[i] == 5)
                five++;
        }
        return true;
    }
};