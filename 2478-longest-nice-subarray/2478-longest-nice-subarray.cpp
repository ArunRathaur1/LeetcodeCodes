class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int length=0;
        int left=0;
        int l=nums.size();
        for(int i=0;i<l;i++){
            int value=nums[i];
            int p=1;
            for(int j=i+1;j<l;j++){
                if((value&nums[j])==0){
                    value=value|nums[j];
                    p++;
                }
                else{
                    break;
                }
            }
            length=max(p,length);
        }
        return length;
    }
};