class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(auto i: nums)x=x^i;
        x=(x&(x-1))^x;
        int num1=0;
        int num2=0;
        for(auto i: nums){
            if((i&x)!=0)num1=num1^i;
            else{
                num2=num2^i;
            }
        }
        return {num1,num2};
    }
};