class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int value=INT_MAX;
        int sign=0;
        for(auto i: nums){
            if(abs(i)==value&& sign==1&& i>0){
                sign=0;
            }
            else if(abs(i)<value){
                value=abs(i);
                if(i<0){
                    sign=1;
                }
                else{
                    sign=0;
                }
            }
        }
        return pow(-1,sign)*value;
    }
};