class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(auto i: nums)x=x^i;
        x=(x&(x-1))^x;
        vector<int>bucket1,bucket2;
        for(auto i: nums){
            if((i&x)!=0)bucket1.push_back(i);
            else{
                bucket2.push_back(i);
            }
        }
        int num1=0;
        int num2=0;
        for(auto i: bucket1){
            num1=num1^i;
        }
        for(auto i: bucket2){
            num2=num2^i;
        }
        return {num1,num2};
    }
};