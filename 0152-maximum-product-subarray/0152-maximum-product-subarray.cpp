class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxproduct=INT_MIN;
        for(int i=0;i<n;i++){
            int tem=1;
            for(int j=i;j<n;j++){
                tem=tem*nums[j];
                maxproduct=max(maxproduct,tem);
            }
        }
        return maxproduct;
    }
};