class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int length=0;
        int left=0;
        int l=nums.size();
        int value=0;
        for(int i=0;i<l;i++){
            while((value&nums[i])!=0){
                value=value^nums[left];
                left++;
            }
            value=value|nums[i];
            length=max(length,i-left+1);
        }
        return length;
    }
};